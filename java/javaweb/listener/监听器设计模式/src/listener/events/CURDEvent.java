package listener.events;

import listener.listenerable.IListenerable;

// 定义事件类
public class CURDEvent implements ICURDEvent {
    private IListenerable eventSource; // 事件源
    private String methodName; // 事件源所执行的方法名称

    public CURDEvent(IListenerable eventSource, String methodName) {
        super();
        this.eventSource = eventSource;
        this.methodName = methodName;
    }

    // 获取事件源对象
    @Override
    public IListenerable getEventSource() {
        return eventSource;
    }

    // 根据事件源所执行的不同的方法，返回不同的事件类型
    @Override
    public String getEventType() {
        String eventType = null;
        if(methodName.startsWith("save")) {
            eventType = CRE_EVENT;
        } else if(methodName.startsWith("remove")) {
            eventType = DEL_EVENT;
        } else if(methodName.startsWith("modify")) {
            eventType = UPD_EVENT;
        } else if(methodName.startsWith("find")) {
            eventType = RET_EVENT;
        } else {
            eventType = "have not this event type";
        }

        return eventType;
    }
}
