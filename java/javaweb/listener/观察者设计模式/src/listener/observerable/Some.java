package listener.observerable;

import java.util.List;
import java.util.ArrayList;

import listener.observers.*;

/*
 *   观察者设计模式，定义了一种一对多的关联关系。一个对象 A 与多个对象 B、
 * C、D 之间建立“被观察与观察关系”。当对象 A 的状态发生改变时，通知所有
 * 观察者对象 B、C、D。当观察者对象 B、C、D 在接收到 A 的通知后，根据自身
 * 实际情况，做出相应改变。
 *   当然，观察者与被观察者指的都是具有某一类功能的对象，所以这里的观察者
 * 与被观察者都是指的接口，而真正的观察者对象与被观察者对象，是实现了这些
 * 接口的类的对象。
 */

// 定义被观察者，被观察者只能有一个
public class Some implements IObserverable {
    private List<IObserver> observers;

    public Some() {
        observers = new ArrayList<IObserver>();
    }

    // 添加观察者
    public void addObserver(IObserver observer) {
        observers.add(observer);
    }

    // 删除观察者
    public void removeObserver(IObserver observer) {
        observers.remove(observer);
    }

    // 通知所有观察者
    public void notifyObservers(String message) {
        for(IObserver observer : observers) {
            observer.handleNotify(message);
        }
    }
}
