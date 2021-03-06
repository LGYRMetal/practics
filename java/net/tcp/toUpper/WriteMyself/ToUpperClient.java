package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;

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
                                  ToUpperServer.LISTENING_PORT)) {

        // 2.获取Socket对象的输入出流，准备发送数据到服务端,和接收服务端的
        //   反馈信息
        OutputStream out = s.getOutputStream();
        InputStream in = s.getInputStream();

        // 提示信息
        System.out.println("请输入信息, 只能是英文，中文不存在大小写:");

        // 3.准备数据
        String line = null;
        // 获取键盘输入
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        while((line = br.readLine()) != null) {
            if("over".equalsIgnoreCase(line)) {
                System.out.println("GoodBye next time~~");
                s.close();
                System.exit(0);
            } else {
                // BufferedReader.readLine()不包含任何行结束符，所以手动添加
                // 一个换行
                line += '\n';
                // 4.发送数据
                out.write(line.getBytes());

                // 5.接受反馈信息，并输出
                BufferedReader feedbackBR =
                    new BufferedReader(new InputStreamReader(in));
                System.out.println(feedbackBR.readLine());
            }
        }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
