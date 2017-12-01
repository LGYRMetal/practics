package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.ServerSocket;

public class NetCopyFileServer implements Runnable {
    // Field
    public static final int LISTENING_PORT = 65535;
    private Socket socket;

    // Constructor
    public NetCopyFileServer(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        /*
         * Deal with every connected Socket
         */
        // Print welcome info
        String ip = socket.getInetAddress().getHostAddress();
        System.out.println(ip + " is connected!");

        try {
            // 1. Get the data source: socket's InputStream.
            InputStream socketIn = socket.getInputStream();
            PrintWriter socketOut =
                new PrintWriter(socket.getOutputStream(), true);

            // Get the copied file name
            String fileName =
                new BufferedReader(
                        new InputStreamReader(socketIn)).readLine();
            // 返回给客户端，接收到的文件名，让客户端确定文件名是否已正确收
            socketOut.println(fileName);

            // 创建同名文件
            File file = new File(fileName);
            // 判断文件是否已存在
            if(file.exists()) {
                socketOut.println("文件已存在!");
                return;
            }

            // 2. Data destination: local file.
            // Get the file name which is being copied.
            PrintStream out = new PrintStream(file);

            byte[] buf = new byte[1024];
            int len = 0;
            while((len = socketIn.read(buf, 0, buf.length)) != -1) {
                out.write(buf, 0, len);
                out.flush();
            }

            socket.shutdownOutput();
            socket.close();
            // Print info
            System.out.println(ip + " is disconnect!");
        } catch(Exception e) {
            // 3. return feedback info
            try(PrintWriter socketOut =
                    new PrintWriter(socket.getOutputStream(), true)) {
                socketOut.println("拷贝文件到服务器失败!");
            } catch(Exception eInner) {
                eInner.printStackTrace();
            }
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Socket s = null;
        // 1. Create Server Socket, and bind listening port.
        try(ServerSocket ss = new ServerSocket(LISTENING_PORT)) {
            // 2. Wait the coming Socket throught the ServerSocket's accept
            //    method.
            while(true) {
                s = ss.accept();

                // 3. Throw the accepted socket to the new thread to deal
                // with.
                new Thread(new NetCopyFileServer(s)).start();
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
