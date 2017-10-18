public class WaitNotifyTest {
    public static void main(String[] args) {
        Thread t1 = new Thread(new Processor());
        Thread t2 = new Thread(new Processor());

        t1.setName("t1");
        t2.setName("t2");

        t1.start();
        try{Thread.sleep(1000);} catch(Exception e) {e.printStackTrace();}
        t2.start();

        while(true) {
            synchronized(t2) {
                t2.notify();
            }
            try{Thread.sleep(1000);} catch(Exception e) {e.printStackTrace();}
            synchronized(t1) {
                t1.notify();
            }
        }
    }
}

class Processor implements Runnable {
    public void run() {
        int t1 = 1;
        int t2 = 2;
        String t = Thread.currentThread().getName();

        while(true) {
            if("t1".equals(t)) {
                System.out.println(t + "-->" + t1);
                t1 += 2;
            }
            if("t2".equals(t)) {
                System.out.println(t + "-->" + t2);
                t2 += 2;
            }

            synchronized(this) {
                try{this.wait();} catch(Exception e) {e.printStackTrace();}
            }
        }
    }
}
