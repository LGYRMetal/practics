package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.net.Socket;

class UserServerThread implements Runnable {
    // Field
    Socket s;

    // Constructor
    public UserServerThread(Socket s) {
        this.s = s;
    }

    public void run() {
        // 获取客户端ip地址
        String ip = s.getInetAddress().getHostAddress();
        System.out.println(ip + " is connected.");

        try(
        // 1. 获取数据源：Socket输入流
        BufferedReader socketIn =
            new BufferedReader(new InputStreamReader(s.getInputStream()));

        // 2. 获取目的: Socket输出流
        PrintWriter socketOut = new PrintWriter(s.getOutputStream(), true);
        ) {
        // 3. 处理业务
            String line = null;
            while((line = socketIn.readLine()) != null) {
                socketOut.println(line);
            }

        // 4. 关闭资源
            s.close();
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
