package com.lgyrmetal;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.io.InputStream;
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
            InputStream in = socket.getInputStream();

            // 2. Data destination: local file.
            // Get the file name which is being copied.
            String fileName =
                new BufferedReader(new InputStreamReader(in)).readLine();
            PrintStream out = new PrintStream(fileName);

System.out.println("file name: " + fileName);
            File file = new File(fileName);
            if(file.exists()) {
System.out.println("file is already exits!");
                PrintWriter socketOut =
                    new PrintWriter(socket.getOutputStream(), true);
                socketOut.println("文件已存在!");
System.out.println("file is already exits!");
                return;
            }

            // 3. Skip the file name.
            // Get the bytes length of the file name.
            // The start of the file content is fileNameLen +
            // "\n".getBytes().length
            //long fileNameLen = (fileName + "\n").getBytes().length;
            //in.skip(fileNameLen);

            byte[] buf = new byte[1024];
            int len = 0;
            while((len = in.read(buf, 0, buf.length)) != -1) {
System.out.println("Writing file content!");
                out.write(buf, 0, len);
                out.flush();
            }

            socket.close();
// Print info
System.out.println(ip + " is disconnect!");

        } catch(Exception e) {
            // 4. return feedback info
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
