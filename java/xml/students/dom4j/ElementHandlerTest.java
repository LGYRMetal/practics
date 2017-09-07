package dom4j;

import java.io.File;

import org.dom4j.*;
import org.dom4j.io.SAXReader;

public class ElementHandlerTest {
    public static void main(String[] args) {
        SAXReader saxReader = new SAXReader();
        File file = new File("students.xml");

        // 添加一个ElementHandler实例
        saxReader.addHandler("/students/student", new StudentHandler());
        try {
            saxReader.read(file);
        } catch (DocumentException e) {
            System.out.println(e.getMessage());
        }
    }

    // 定义StudentHandler处理器类，对<student>元素进行处理
    private static class StudentHandler implements ElementHandler {
        public void onStart(ElementPath path) {
            Element elt = path.getCurrent();
            System.out.println("Found student: " +
                    elt.attributeValue("sn"));
            // 添加对子元素<name>的处理器
            path.addHandler("name", new NameHandler());
        }
        public void onEnd(ElementPath path) {
            // 移除对子元素<name>的处理器
            path.removeHandler("name");
        }
    }

    // 定义NameHandler处理器类，对<student>的子元素<name>进行处理
    private static class NameHandler implements ElementHandler {
        public void onStart(ElementPath path) {
            System.out.println("path: " + path.getPath());
        }

        public void onEnd(ElementPath path) {
            Element elt = path.getCurrent();
            // 输出<name>元素的名字和它的文本内容
            System.out.println(elt.getName() + ": " + elt.getText());
        }
    }
}
