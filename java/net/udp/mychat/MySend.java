package mychat;

import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.InetAddress;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class MySend implements Runnable {
    // Constructor
    public MySend() {}

    public void run() {
        // 创建UDP Socket对象
        try(DatagramSocket ds = new DatagramSocket()) {
            while(true) {
                // 接收键盘录入
                byte[] buf = new byte[1024 * 64]; //UDP包最大不能超过64k
                String line = new BufferedReader(
                        new InputStreamReader(System.in)).readLine();
                buf = line.getBytes();

                // 创建UDP数据报包对象
                DatagramPacket dp = new DatagramPacket(
                        buf,
                        buf.length,
                        InetAddress.getByName("localhost"),
                        10000);

                // 发送数据
                ds.send(dp);

                if("886".equals(line)) {
                    // 关闭UDP Socket服务
                    ds.close();
                    break;
                }
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
