
package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.net.Socket;

public class MyBrowser {
    public static void main(String[] args) {
        try(
        // 1. 创建Socket对象，并绑定服务器ip和port
        Socket s = new Socket("localhost", 8080);

        // 2. 输入: Socket输入流
        BufferedReader in =
            new BufferedReader(new InputStreamReader(s.getInputStream()));

        // 3. 输出: Socket输出流
        PrintWriter out = new PrintWriter(s.getOutputStream(), true);
        ) {
            // http请求头
            String httpRequestHead =
                "GET / HTTP/1.1\n" +
                "Host: localhost:8080\n" +
                "Connection: keep-alive\n" +
                "Upgrade-Insecure-Requests: 1\n" +
                "User-Agent: Mozilla/5.0 (X11; Linux x86_64) " +
                "AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu " +
                "Chromium/62.0.3202.94 Chrome/62.0.3202.94 " +
                "Safari/537.36\n" +
                "Accept: text/html,application/xhtml+xml,application/xml;" +
                "q=0.9,image/webp,image/apng,*/*;q=0.8\n" +
                "Accept-Encoding: gzip, deflate, br\n" +
                "Accept-Language: zh-CN,zh;q=0.9\n\n";

            // 发送请求
            out.println(httpRequestHead);

            // 接收应答信息
            String line = null;
            while((line = in.readLine()) != null) {
                System.out.println(line);
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
