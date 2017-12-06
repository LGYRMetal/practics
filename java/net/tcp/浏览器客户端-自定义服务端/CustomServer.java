package com.lgyrmetal;

import java.net.ServerSocket;
import java.net.Socket;

public class CustomServer {
    public static void main(String[] args) {
        // 1. 创建服务端Socket对象
        try {
            ServerSocket ss = new ServerSocket(65534);

            while(true) {
                Socket s = ss.accept();
                new Thread(new UserServerThread(s)).start();
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
