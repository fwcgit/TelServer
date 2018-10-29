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
#include "string.h"
#include "j_callback.h"

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
	jlog(1,"jni server init");
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
    if(NULL != gVM)
    {
        ret = (*gVM)->AttachCurrentThread(gVM,(void **)&env,NULL);
        if(ret == 0 && NULL != env)
        {
            jclass cls = (*env)->GetObjectClass(env,gObj);
            jmethodID mid =(*env)->GetMethodID(env,cls,"newClientConnect","(ILjava/lang/String;)V");
            (*env)->CallVoidMethod(env,gObj,mid,(*env)->NewStringUTF(env,session));
            
            (*gVM)->DetachCurrentThread(gVM);
        }
    }
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
            jmethodID mid =(*env)->GetMethodID(env,cls,"closeClinetConnect","(ILjava/lang/String;)V");
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
