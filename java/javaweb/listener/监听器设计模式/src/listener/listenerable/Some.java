package listener.listenerable;

import listener.events.ICURDEvent;
import listener.listenerable.*;
import listener.listeners.*;
import listener.events.*;

public class Some implements IListenerable {
    private IListener listener;

    // 注册监听器
    @Override
    public void setListener(IListener listener) {
        this.listener = listener;
    }

    // 出发监听器
    @Override
    public void triggerListener(ICURDEvent event) {
        listener.handle(event);
    }

    // 改进事件源，让事件源处理真正的业务逻辑
    public void saveStudent() {
        System.out.println("向DB中插入了一条数据");
        ICURDEvent event = new CURDEvent(this, "saveStudent");
        triggerListener(event);
    }

    public void removeStudent() {
        System.out.println("从DB中删除了一条数据");
        ICURDEvent event = new CURDEvent(this, "removeStudent");
        triggerListener(event);
    }

    public void modifyStudent() {
        System.out.println("修改了DB中的一条数据");
        ICURDEvent event = new CURDEvent(this, "modifyStudent");
        triggerListener(event);
    }

    public void findStudent() {
        System.out.println("在DB中执行了一次查询");
        ICURDEvent event = new CURDEvent(this, "findStudent");
        triggerListener(event);
    }
}
