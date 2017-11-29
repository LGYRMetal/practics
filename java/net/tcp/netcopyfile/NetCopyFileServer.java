package com.lgyremtel;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.io.OutputStream;

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
        try {
            // 1. Get the socket's InputStream.
            InputStream in = socket.getInputStream();

            // 2. Get the file name which is being copied.
            String fileName =
                new BufferedReader(new InputStreamReader(in)).readLine();

            // 3. Get the file content start point.
            // Get the bytes length of the file name.
            int fileNameLen = fileName.getBytes().length;
            // The start of the file content is fileNameLen +
            // "\n".getBytes().length
            int fileContentStart = fileNameLen + "\n".getBytes().length;

            // 4. Read the file content, and output the content to local.
            byte[] buf = new byte[1024];
            in.read(buf, fileContentStart,);

            FileOutputStream fos = new FileOutputStream(fileName, true);
            fos.write(buf);
            fos.flush();

        } catch(Exception e) {
            // 5. return feedback info
            try(OutputStream out = socket.getOutputStream()) {
                out.write("拷贝文件到服务器失败!".getBytes());
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
            s = ss.accept();
        } catch(Exception e) {
            e.printStackTrace();
        }

        // 3. Throw the accepted socket to the new thread to deal with.
        new Thread(new NetCopyFileServer(s)).start();
    }
}
