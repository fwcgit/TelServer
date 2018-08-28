package com.fu.server;
import java.io.File;
public class ServerLib{

	static{
		//System.loadLibrary("server");
		File file = new File("/home/linux/Desktop/TelServer/src/com/fu/server/libserver.so");
		System.load(file.getAbsolutePath());
	}

	public native void starpServer(int port);

	public native void closeServer();

	public native void sendData(String session,byte[] data);

	public native void sendCmd(String session,int cmd);

	public native void closeClient(int session);

	public native String[] getClientList();

	public void newClientConnect(String session)
	{
		System.out.println("jni_newClientConnect"+session);
	}

	public void closeClinetConnect(String  session)
	{
		System.out.println("jni_closeClinetConnect"+session);
	}
	
	public  void LOG(int type,String txt)
	{
		System.out.println("log->type:"+type+"----txt"+txt);
	}
}
