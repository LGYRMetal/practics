package listener.observers;

// 定义二号观察者
public class SecondObserver implements IObserver {
    public void handleNotify(String message) {
        System.out.println("二号观察者接受到消息 【" + message +
                "】 ，正在处理中。。。");
    }
}
