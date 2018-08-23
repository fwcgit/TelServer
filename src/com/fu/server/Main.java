package com.fu.server;
import java.util.Scanner;

public class Main{

	public static void main(String[] args){

		ServerLib sl = new ServerLib();
		sl.starpServer(28898);
	 	Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			String str = sc.next();
			if(str.equals("exit"))
			{
				sl.closeServer();
			}else if(str.equals("ls"))
			{
				String table[] = sl.getClientList();
				if(null != table)
				{
					for(int i = 0 ; i < table.length ; i++){
						System.out.println("client seesion:"+table[i]);
					}
				}
			}
		}
	}
}

