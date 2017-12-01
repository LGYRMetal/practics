package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;

import java.net.Socket;

public class NetCopyFileClient {
    public static void main(String[] args) {
        // Get the file name, destination ip, destination port
        if(args.length != 2) {
            usage("缺少必要的参数!");
            return;
        }

        String filePath = args[0];
        if(filePath.isEmpty()) {
            usage("无效的文件名!");
            return;
        }

        String destination = args[1];
        if(!destination.matches("(((l|L)(o|O)(c|C)(a|A)(l|L)(h|H)(o|O)(s|S)(t|T))|(((25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))\\.){3}(25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))))\\:((6553[0-5])|(655[0-2]\\d)|(65[0-4]\\d{2})|(6[0-4]\\d{3})|(([1-5]\\d{4})|([1-9]\\d{3})|([1-9]\\d{2})|([1-9]?\\d)))")) {
            usage("无效的目标IP地址");
            return;
        }

        String[] splitDestination = destination.split(":");
        String ip = splitDestination[0];
        int port = Integer.valueOf(splitDestination[1]).intValue();

        // 1. create Client Socket
        try(Socket s = new Socket(ip, port)) {
            File file = new File(filePath);
            String fileName = file.getName();

            // 2. Get the io Stream of Socket
            BufferedReader socketIn =
                new BufferedReader(
                        new InputStreamReader(s.getInputStream()));
            OutputStream socketOut = s.getOutputStream();

            // 3. Send the file name first.
            socketOut.write((fileName + "\n").getBytes());

            // 如果服务端返回正确的文件名，才开始传输文件内容
            if(fileName.equals(socketIn.readLine())) {
                // 4. Prepare file content, and then send data.
                FileInputStream fis = new FileInputStream(file);
                int len = 0;
                byte[] buf = new byte[1024];
                while((len = fis.read(buf, 0, buf.length)) != -1) {
                    socketOut.write(buf, 0, len);
                }
                s.shutdownOutput();
                // 5. Accept feedback if copied failed.
                String line = null;
                while((line = socketIn.readLine()) != null) {
                    System.out.println(line);
                }
            } else {
                System.out.println("拷贝文件失败！");
            }
        } catch(Exception e) {
            System.out.println("拷贝文件失败!");
            e.printStackTrace();
        }

        System.exit(0);
    }

    private static void usage(String errMsg) {
        String classname = null;
        try {
            classname =
                Class.forName("com.lgyrmetal.NetCopyFileClient").getName();
        } catch(ClassNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(errMsg);
        System.out.println("Usage:");
        System.out.println("java " + classname +
                " filename" + " destinationIP:port");
    }
}
