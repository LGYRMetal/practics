/*
 * 按照视频中重写的MyChat
 */
package yourchat;

import java.net.DatagramSocket;

public class YourChat {
    public static void main(String[] args) {
        try {
            new Thread(new YourSend(new DatagramSocket())).start();
            new Thread(new YourReceive(new DatagramSocket(10000))).start();
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
