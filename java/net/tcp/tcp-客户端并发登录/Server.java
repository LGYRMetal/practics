package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.net.ServerSocket;
import java.net.Socket;

public class Server implements Runnable {
    // Field
    private Socket s;

    // Contructor
    public Server(Socket s) {
        this.s = s;
    }

    public static void main(String[] args) {
        // 1. 创建服务端Socket，并绑定监听端口
        ServerSocket ss = null;
        try {
            ss = new ServerSocket(65535);
        } catch(Exception e) {
            e.printStackTrace();
        }

        while(true) {
            // 2. 获取客户端Socket
            try {
                Socket socket = ss.accept();
                new Thread(new Server(socket)).start();
            } catch(Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void run() {
        // 3. 获取数据源：客户端Socket输入流
        try(BufferedReader socketIn =
            new BufferedReader(new InputStreamReader(s.getInputStream()));

        // 4. 获取目的：客户端输出流
        PrintWriter socketOut =
            new PrintWriter(s.getOutputStream(), true);) {
            // 5. 处理业务逻辑
            int counter = 3;    // 最多就输入3次
            while(counter-- > 0) {
                //   1) 接收客户端输入
                String username = socketIn.readLine();
                if(username == null || "null".equals(username)) {
                    break;
                }

                //   2) 判断客户端输入是否存在于"user.txt"中
                if(exists(username)) {
                    System.out.println(username + "已登录");
                    socketOut.println(username + "欢迎光临");
                    s.shutdownOutput();
                    break;
                } else {
                    System.out.println(username + "尝试登录");
                    socketOut.println("用户\"" + username + "\"不存在," +
                            "请重新输入, 您还有" + counter + "次机会");
                    // 解决客户端3次输错后还多让输一次
                    if(counter > 0)
                        socketOut.println(counter);
                    else
                        s.shutdownOutput();
                }
            }
            s.close();
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    private boolean exists(String username) {
        try(BufferedReader fileIn =
            new BufferedReader(new FileReader("user.txt"));) {

            String record = null;
            while((record = fileIn.readLine()) != null) {
                if(record.equals(username)) {
                    return true;
                }
            }
        } catch(Exception e) {
            e.printStackTrace();
        }

        return false;
    }
}
