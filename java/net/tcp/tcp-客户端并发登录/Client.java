package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.net.Socket;

public class Client {
    public static void main(String[] args) {
        // 1. 创建Socket对象，并绑定ip和port
        try(Socket s = new Socket("localhost", 65535);
        // 2. 获取数据源:
        //   1) 键盘录入
        BufferedReader brIn =
            new BufferedReader(new InputStreamReader(System.in));
        //   2) 网络输入流：接收服务端的反馈信息
        BufferedReader socketIn =
            new BufferedReader(new InputStreamReader(s.getInputStream()));

        // 3. 获取目的：网络输出流
        PrintWriter socketOut =
            new PrintWriter(s.getOutputStream(), true)) {
            // 4. 处理业务逻辑
            //   1) 打印客户端提示信息
            System.out.print("用户名: ");
            //   2) 发送用户键盘输入
            socketOut.println(brIn.readLine());
            //   3) 打印服务器的反馈信息
            System.out.println(socketIn.readLine());
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
