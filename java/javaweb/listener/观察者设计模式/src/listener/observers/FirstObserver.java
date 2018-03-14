package listener.observers;

// 定义一号观察者, 观察者可以有多个
public class FirstObserver implements IObserver {
    public void handleNotify(String message) {
        System.out.println("一号观察者接收到消息 【" + message + 
                "】 ， 正在处理中。。。");
    }
}
