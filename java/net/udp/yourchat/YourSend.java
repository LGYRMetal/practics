package yourchat;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class YourSend implements Runnable {
    // Field
    private DatagramSocket ds;

    // Contructor
    public YourSend(DatagramSocket ds) {
        this.ds = ds;
    }

    public void run() {
        // 创建BufferedReader准备接受用户键盘输入
        try(BufferedReader br = new BufferedReader(
                    new InputStreamReader(System.in))) {
            String line = null;

            while((line = br.readLine()) != null) {
                // 创建UDP数据报包，准备封装用户要发送的数据
                byte[] buf = new byte[1024 * 64]; // UDP包最大不超过64k
                buf = line.getBytes();
                DatagramPacket dp = new DatagramPacket(
                        buf,
                        buf.length,
                        InetAddress.getByName("localhost"),
                        10000);

                // 发送数据包
                ds.send(dp);

                if("886".equals(line)) {
                    break;
                }
            }
        } catch(Exception e) {
            throw new RuntimeException("发送端错误!");
        }
    }
}
