package com.lgyrmetal;

import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;

import java.net.Socket;

public class NetCopyFileClient {
    public static void main(String[] args) {
        // Get the file name, destination ip, destination port
        if(args.length != 2) {
            usage("缺少必要的参数!");
            return;
        }

        String fileName = args[0];
        if(fileName.isEmpty()) {
            usage("无效的文件名!");
            return;
        }

        String destination = args[1];
        if(!destination.matches("(((25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))\\.){3}(25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d))))\\:((6553[0-5])|(655[0-2]\\d)|(65[0-4]\\d{2})|(6[0-4]\\d{3})|(([1-5]\\d{4})|([1-9]\\d{3})|([1-9]\\d{2})|([1-9]?\\d)))")) {
            usage("无效的目标IP地址");
            return;
        }

        String[] splitDestination = destination.split(":");
        String ip = splitDestination[0];
        int port = Integer.valueOf(splitDestination[1]).intValue();

        // 1. create Client Socket
        try(Socket s = new Socket(ip, port)) {
            // 2. Get the io Stream of Socket
            InputStream in = s.getInputStream();
            OutputStream out = s.getOutputStream();

            // 3. Send the file name first.
            out.write((fileName + "\n").getBytes());

            // 4. Prepare file content, and then send data.
            FileInputStream fis = new FileInputStream(fileName);
            int len = 0;
            byte[] buf = new byte[1024];
            while((len = fis.read(buf, 0, buf.length)) != -1) {
                out.write(buf, 0, len);
            }

            // 5. Accept feedback if copied failed.
            while((len = in.read(buf, 0, buf.length)) != -1) {
                System.out.write(buf, 0, len);
            }
        } catch(Exception e) {
            System.out.println("拷贝文件失败!");
            e.printStackTrace();
        }
    }

    private static void usage(String errMsg) {
        String classname = null;
        try {
            classname = Class.forName("NetCopyFileClient").getName();
        } catch(ClassNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(errMsg);
        System.out.println("Usage:");
        System.out.println("java " + classname +
                " filename" + " destinationIP:port");
    }
}
