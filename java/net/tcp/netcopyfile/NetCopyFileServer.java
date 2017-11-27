package com.lgyremtel;

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
    }

    public static void main(String[] args) {
        // 1. Create Server Socket, and bind listening port.
        ServerSocket ss = new ServerSocket(LISTENING_PORT);

        // 2. Wait the coming Socket throught the ServerSocket's accept
        //    method.
        Socket s = ss.accept();

        // 3. Throw the accepted socket to the new thread to deal with.
        new Thread(new NetCopyFileServer(s)).start();
    }
}
