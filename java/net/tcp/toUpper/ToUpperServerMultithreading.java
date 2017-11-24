package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;

import java.net.ServerSocket;
import java.net.Socket;

/*
 * 需求：建立一个文本转换服务器。
 *       客户端给服务端发送文本，服务端会将文本转换成大写再返回给客户端。而
 *       且客户端可以不断的进行文本转换。当客户端输入over时，转换结束。
 */

public class ToUpperServerMultithreading implements Runnable {
    public static final int LISTENING_PORT = 65535;

    private Socket socket;
    
    public ToUpperServerMultithreading(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            // 获取客户端ip，并打印客户端信息
            String ip = socket.getInetAddress().getHostAddress();
            System.out.println(ip + "已连接");

            // 3.获取客户端对象的读取流，读取客户发送过来的数据
            InputStream in = socket.getInputStream();
            BufferedReader br =
                new BufferedReader(new InputStreamReader(in));
            String line = null;

            // 4.获取客户端对象的输出流，处理数据，输出反馈信息
            OutputStream out = socket.getOutputStream();

            while((line = br.readLine()) != null) {
                //if("over".equalsIgnoreCase(line)) {
                //    out.write("Good Bye next time~~".getBytes());
                //    // 5.关闭客户端链接
                //    s.close();
                //} else {
                line = line.toUpperCase();
                line += '\n';
                out.write(line.getBytes());
                //}
            }
            // 5.关闭客户端链接
            socket.close();
            System.out.println(ip + "已断开");
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        // 1.创建服务端Socket服务，通过ServerSocket类，并监听一个端口
        try(ServerSocket ss = new ServerSocket(LISTENING_PORT)) {

            while(true) {
                // 2.通过ServerSocket的accept方法获取连接过来的客户端对象
                Socket s = ss.accept();

                new Thread(new ToUpperServerMultithreading(s)).start();
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
