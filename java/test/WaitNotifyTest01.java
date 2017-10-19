public class WaitNotifyTest01 {
    public static void main(String[] args) {
        Processor p = new Processor();

        Thread t1 = new Thread(p);
        Thread t2 = new Thread(p);

        t1.setName("t1");
        t2.setName("t2");

        t1.start();
        try{Thread.sleep(1000);} catch(Exception e) {e.printStackTrace();}
        t2.start();
        try{Thread.sleep(1000);} catch(Exception e) {e.printStackTrace();}

        while(true) {
            synchronized(p1) {
                p1.notify();
                //System.out.println("p1.notify()");
            }
            try{Thread.sleep(1000);} catch(Exception e) {e.printStackTrace();}
            synchronized(p2) {
                p2.notify();
                //System.out.println("p2.notify()");
            }
            try{Thread.sleep(1000);} catch(Exception e) {e.printStackTrace();}
        }
    }
}

class Processor implements Runnable {
    public void run() {
        String t = Thread.currentThread().getName();

        for(int i = 0; ; i++) {
            System.out.println(t + "-->" + i);

            synchronized(this) {
                try{this.wait();} catch(Exception e) {e.printStackTrace();}
            }
        }
    }
}
