package listener.events;

import listener.listenerable.*;

// CURD含义: 增删改查
// C: Create, 增加
// U: Update, 修改
// R: Retrieve, 检索
// D: Delete, 删除

// 通常，对于事件对象，我们一般是需要从事件对象中获取到事件源对象的
public interface ICURDEvent {
    // 声明事件类型，在接口中声明的成员变量，默认是public static,不写也是
    public static String CRE_EVENT = "create event";
    public static String UPD_EVENT = "update event";
    public static String RET_EVENT = "retrieve event";
    public static String DEL_EVENT = "delete event";

    // 获取事件源对象
    public abstract IListenerable getEventSource();

    // 获取事件类型
    public abstract String getEventType();
}
