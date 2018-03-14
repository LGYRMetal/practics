package listener.observers;

// 定义观察者接口
public interface IObserver {
    // 处理被观察者发送的消息
    public abstract void handleNotify(String message);
}
