package listener.observerable;

import listener.observers.*;

// 定义被观察者接口
public interface IObserverable {
    // 添加观察者
    public abstract void addObserver(IObserver observer);

    // 删除观察者
    public abstract void removeObserver(IObserver observer);

    // 通知所有观察者
    public abstract void notifyObservers(String message);
}
