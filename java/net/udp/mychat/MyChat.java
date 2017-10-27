/*
 * 我自己写的
 */
package mychat;

public class MyChat {
    public static void main(String[] args) {
        Thread mySend   = new Thread(new MySend());
        Thread myReceive = new Thread(new MyReceive());

        mySend.start();
        myReceive.start();
    }
}
