package listener.listeners;

import listener.events.ICURDEvent;

// 定义监听器类
public class CURDListener implements IListener {
    // 处理事件
    @Override
    public void handle(ICURDEvent event) {
        String eventType = event.getEventType();
        String opt = null;

        if(ICURDEvent.CRE_EVENT.equals(eventType)) {
            opt = "添加";
        } else if(ICURDEvent.UPD_EVENT.equals(eventType)) {
            opt = "修改";
        } else if(ICURDEvent.RET_EVENT.equals(eventType)) {
            opt = "查询";
        } else if(ICURDEvent.DEL_EVENT.equals(eventType)) {
            opt = "删除";
        }
        System.out.println("事件源执行了 " + opt + " 操作");
    }
}
