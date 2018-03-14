package listener.test;

import listener.listeners.*;
import listener.listenerable.*;
import listener.events.*;

public class Test {
    public static void main(String[] args) {
        // 创建监听器对象
        IListener listener = new CURDListener();

        // 创建事件源对象
        //IListenerable some = new Some();
        Some some = new Some(); // 改进后，Some中包含一些IListenerable中
                                // 不存在的方法，所以要用Some

        // 创建事件对象
        //ICURDEvent event = new CURDEvent(some, "saveStudent");

        // 为事件源注册监听器
        some.setListener(listener);

        // 事件源触发监听器
        //some.triggerListener(event);

        // 改进后的代码，让事件源处理真正的逻辑业务
        some.saveStudent();
        some.removeStudent();
        some.modifyStudent();
        some.findStudent();
    }
}
