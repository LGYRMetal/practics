package yourchat;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

class YourReceive implements Runnable {
    // Field
    private DatagramSocket ds;

    // Contructor
    public YourReceive(DatagramSocket ds) {
        this.ds = ds;
    }

    public void run() {
        try {
            while(true) {
                byte[] buf = new byte[1024 * 64];

                // 创建UDP数据报包，准备接受数据
                DatagramPacket dp = new DatagramPacket(buf, buf.length);

                // 接收数据
                ds.receive(dp);

                // 获取发送端IP和接收的数据
                String ip = dp.getAddress().getHostAddress();
                
                System.out.println(
                        ip + ": " +
                        new String(dp.getData(), 0, dp.getLength()));
            }
        } catch(Exception e) {
            throw new RuntimeException("接收端错误!");
        }
    }
}
