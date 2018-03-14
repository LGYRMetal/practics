package listener.listeners;

import listener.events.*;

// 定义监听器接口
public interface IListener {
    // 处理事件
    public abstract void handle(ICURDEvent event);
}
