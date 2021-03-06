/*********************************************************************
File Name: jni_server.c
Author: fuweicheng
mail: fu_huaicheng@163.com
Created Time: Fri 17 Aug 2018 02:52:11 PM CST
Description:
*************************************************************/
#include "com_fu_server_ServerLib.h"
#include "server.h"
#include "log.h"
#include "jni.h"
#include "client_info.h"

#include "j_callback.h"
#include "crc.h"

char logStr[200];
JavaVM *gVM;
jobject gObj;

jstring charTojstring(JNIEnv* env, const char* pat) 
{
	jclass strClass = (*env)->FindClass(env,"Ljava/lang/String;");
	jmethodID ctorID = (*env)->GetMethodID(env,strClass, "<init>", "([BLjava/lang/String;)V");
	jbyteArray bytes = (*env)->NewByteArray(env,(jsize)strlen(pat));
	(*env)->SetByteArrayRegion(env,bytes, 0, (jsize)strlen(pat), (jbyte*) pat);
	return (jstring) (*env)->NewObject(env,strClass, ctorID, bytes);
}
/*
 * Class:     com_fu_server_ServerLib
 * Method:    starpServer
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_fu_server_ServerLib_starpServer
  (JNIEnv *env, jobject obj, jint port)
{
	gObj = (*env)->NewGlobalRef(env,obj);
	init_config(port);
	starp_server();
	jlog(1,"jni server init....");
}

JNIEXPORT jlong JNICALL Java_com_fu_server_ServerLib_sendCmd
(JNIEnv *env, jobject obj, jstring session, jbyte cmd)
{
    ssize_t ret;
    package pk;
    const char *c_session;
    char *user_s;
    
    c_session = (*env)->GetStringUTFChars(env,session,0);
    user_s = (char *)malloc(sizeof(char) * (strlen(c_session)));
    
    pk.head.type = MSG_TYPE_CMD;
    pk.head.len = 1;
    pk.head.ck = M_CK(pk.head);
    pk.data = (char *)malloc(sizeof(char));
    memcpy(pk.data, (char*)&cmd, 1);
    ret = send_user(user_s,(char*)&pk,sizeof(msg_head));
    
    free(pk.data);
    free(user_s);
    
    return ret;
}

JNIEXPORT jlong JNICALL Java_com_fu_server_ServerLib_sendData
(JNIEnv *env, jobject obj, jstring session, jbyteArray bytes)
{
    ssize_t ret;
    char *data;
    jbyte *jb;
    const char *c_session;
    char *user_s;
    char log[10];
    
    int len = (*env)->GetArrayLength(env,bytes);
    sprintf(log, "array len %d",len);
    jlog(1, log);
    printf("array len %d \n",len);
    fflush(stdout);
    jb = (*env)->GetByteArrayElements(env,bytes,0);
    data = (char *)malloc(sizeof(char) * len);
    memset(data,0,len);
    memcpy(data,jb,len);
    
    c_session = (*env)->GetStringUTFChars(env,session,0);
    user_s = (char *)malloc(sizeof(char) * (strlen(c_session)));
    memset(user_s, 0, strlen(c_session));
    strcpy(user_s,c_session);
    
    package msg;
    msg.fd = 0;
    msg.head.type = MSG_TYPE_DATA;
    msg.head.len = len;
    msg.head.ck  = M_CK(msg.head);
    msg.head.crc  = CRC16((unsigned char *)data, len);
    msg.data = malloc(sizeof(char) * (M_SIZE + msg.head.len));
    
    pack_data(msg.data,&msg,M_SIZE,data,msg.head.len);
    
    printf("send_user len %ld \r\n",M_SIZE + msg.head.len);
    send_user(user_s, msg.data, M_SIZE + msg.head.len);

    free(user_s);
    free(data);
    (*env)->ReleaseByteArrayElements(env,bytes,jb,0);
    return ret;
}

/*
 * Class:     com_fu_server_ServerLib
 * Method:    closeServer
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fu_server_ServerLib_closeServer
  (JNIEnv *env, jobject ojb)
{
	stop_server();
}


void client_online(char *session)
{
    int ret;
    JNIEnv *env;
    
    printf("client_online {%s} \r\n",session);
#if 1
    if(NULL != gVM)
    {
        ret = (*gVM)->AttachCurrentThread(gVM,(void **)&env,NULL);
        if(ret == 0 && NULL != env)
        {
            jclass cls = (*env)->GetObjectClass(env,gObj);
            jmethodID mid =(*env)->GetMethodID(env,cls,"newClientConnect","(Ljava/lang/String;)V");
            (*env)->CallVoidMethod(env,gObj,mid,(*env)->NewStringUTF(env,session));
            
            (*gVM)->DetachCurrentThread(gVM);
        }
    }
#endif
}

void client_off_line(char *session)
{
    int ret;
    JNIEnv *env;
    
    if(NULL != gVM)
    {
        ret = (*gVM)->AttachCurrentThread(gVM,(void **)&env,NULL);
        if(ret == 0 && NULL != env)
        {
            jclass cls = (*env)->GetObjectClass(env,gObj);
            jmethodID mid =(*env)->GetMethodID(env,cls,"closeClinetConnect","(Ljava/lang/String;)V");
            (*env)->CallVoidMethod(env,gObj,mid,(*env)->NewStringUTF(env,session));
            
            (*gVM)->DetachCurrentThread(gVM);
        }
    }
}

void jlog(int type,char *ch)
{
	int ret;
	JNIEnv *env;

	if(NULL != gVM)
	{
		ret = (*gVM)->AttachCurrentThread(gVM,(void **)&env,NULL);
		if(ret == 0 && NULL != env)
		{
			jclass cls = (*env)->GetObjectClass(env,gObj);
			jmethodID mid =(*env)->GetMethodID(env,cls,"LOG","(ILjava/lang/String;)V");
			(*env)->CallVoidMethod(env,gObj,mid,type,(*env)->NewStringUTF(env,ch));
			
			(*gVM)->DetachCurrentThread(gVM);
		}
	}
}
/*
 * Class:     com_fu_server_ServerLib
 * Method:    closeClient
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_fu_server_ServerLib_closeClient
  (JNIEnv *env, jobject ojb, jint session)
{
	
}

/*
 * Class:     com_fu_server_ServerLib
 * Method:    getClientList
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_fu_server_ServerLib_getClientList
  (JNIEnv *env, jobject obj)
{
	int count;
	client_info *table;
	jobjectArray objarray;
	jclass cls;
	int i;

	table = get_client_list(&count);

	if(NULL == table)
	{
		return NULL;
	}

	cls = (*env)->FindClass(env,"java/lang/String");
	objarray = (*env)->NewObjectArray(env,count,cls,NULL);

	for(i = 0 ; i < count ; i++)
	{
		(*env)->SetObjectArrayElement(env,objarray,i,(*env)->NewStringUTF(env,(table+i)->code));
	}

	free(table);
	return objarray;

}


jint JNI_OnLoad(JavaVM *vm,void *reservd)
{
	gVM = vm;
	return JNI_VERSION_1_6;
}
