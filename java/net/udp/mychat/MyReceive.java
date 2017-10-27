package mychat;

import java.net.DatagramSocket;
import java.net.DatagramPacket;

class MyReceive implements Runnable {
    // Constructor
    public MyReceive() {}

    public void run() {
        // 创建UDP Socket对象，并绑定端口
        try(DatagramSocket ds = new DatagramSocket(10001)) {
            while(true) {
                // 创建UDP 数据报包，准备接受数据
                byte[] buf = new byte[1024 * 64];
                DatagramPacket dp = new DatagramPacket(buf, buf.length);

                // 接收数据
                ds.receive(dp);

                // 打印数据到控制台
                System.out.println(
                        dp.getAddress().getHostAddress() + ": " +
                        new String(dp.getData()));
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
