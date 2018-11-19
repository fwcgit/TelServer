package com.fu.server;
import java.util.Scanner;

public class Main{

	public static void main(String[] args){

		ServerLib sl = new ServerLib();
		sl.starpServer(28898);
	 	Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){

			String str = sc.nextLine();
			String parList[] = str.split(" ");
			System.out.println("parList:"+parList.length);	
			if(parList.length == 1){
				if(str.equals("exit")){
					sl.closeServer();
					System.exit(0);
				}else if(str.equals("ls")){
					String table[] = sl.getClientList();
					if(null != table)
					{
						for(int i = 0 ; i < table.length ; i++){
							System.out.println("client seesion:"+table[i]);
						}
					}
				}
			}else if(parList.length >= 2)
			{
				if(parList[0].equals("send")){
					if(parList.length == 3)
					{					
						sl.sendData(parList[1],parList[2].getBytes());
					}
				}else if(parList[0].equals("sendm"))
				{
					if(parList.length == 3)
					{					
						sl.sendCmd(parList[1],parList[2].getBytes()[0]);
					}
				}
			}
		}
	}
}

