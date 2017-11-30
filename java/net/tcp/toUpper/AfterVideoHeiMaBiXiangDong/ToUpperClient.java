package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.net.Socket;

/*
 * 需求：建立一个文本转换服务器。
 *       客户端给服务端发送文本，服务端会将文本转换成大写再返回给客户端。而
 *       且客户端可以不断的进行文本转换。当客户端输入over时，转换结束。
 */

public class ToUpperClient {
    public static void main(String[] args) {
        // 1.创建Socket服务，并指定要连接的主机和端口
        try(Socket s = new Socket("localhost",
                    ToUpperServerMultithreading.LISTENING_PORT)) {

        // 2. 获取数据源:获取键盘输入
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        // 3. 获取目的：Socket输出流
        PrintWriter out = new PrintWriter(s.getOutputStream(), true);
        // 接受反馈信息: Socket输入流
        BufferedReader in =
            new BufferedReader(
                    new InputStreamReader(s.getInputStream()));

        // 提示信息
        System.out.println("请输入信息, 只能是英文，中文不存在大小写:");

        // 4. 发送数据，接收反馈数据
        String line = null;
        while((line = br.readLine()) != null) {
            if("over".equalsIgnoreCase(line)) {
                System.out.println("GoodBye next time~~");
                s.close();
                System.exit(0);
            } else {
                // 发送数据
                out.println(line);

                // 5.接受反馈信息，并输出
                System.out.println(in.readLine());
            }
        }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
