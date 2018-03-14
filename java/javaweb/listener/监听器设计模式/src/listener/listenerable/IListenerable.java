package listener.listenerable;

import listener.listeners.*;
import listener.events.*;

// 事件源接口，监听器设计模式与观察者设计模式的一个不同是，监听器(即观察者)
// 一般只有一个
public interface IListenerable {
    // 为事件源注册监听器
    public abstract void setListener(IListener listener);
    // 触发监听器
    public abstract void triggerListener(ICURDEvent event);
}
