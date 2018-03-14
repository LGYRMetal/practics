package listener.test;

import listener.observers.*;
import listener.observerable.*;

// 测试程序
public class Test {
    public static void main(String[] args) {
        // 创建多个观察者对象
        IObserver firstObserver = new FirstObserver();
        IObserver secondObserver = new SecondObserver();

        // 创建被观察者对象
        IObserverable some = new Some();

        // 向被观察者对象添加观察者对象
        some.addObserver(firstObserver);
        some.addObserver(secondObserver);

        // 向所有观察对象发出通知
        some.notifyObservers("全体起立");

        System.out.println("========== 删除一个观察者 ===========");

        some.removeObserver(secondObserver);
        some.notifyObservers("别着急，下一个删除的就是你");
    }
}
