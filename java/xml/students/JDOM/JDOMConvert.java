package JDOM;

import java.io.File;
import java.io.IOException;

import org.jdom2.*;
import org.jdom2.input.SAXBuilder;
import org.jdom2.output.XMLOutputter;
import org.jdom2.output.Format;

public class JDOMConvert {
    public static void main(String[] args) {
        SAXBuilder saxBuilder = new SAXBuilder();
        File file = new File("students.xml");
        try {
            Document doc = saxBuilder.build(file);
            // ---------------- 添加节点 -------------------
            // 创建表示一个学生信息的元素节点
            Element eltStu = new Element("student");
            Element eltName = new Element("name");
            Element eltAge = new Element("age");

            // 设置<name>和<age>元素的文本内容
            eltName.setText("王五");
            eltAge.setText("19");

            // 将<name>和<age>元素添加为<student>元素的内容
            eltStu.addContent(eltName);
            eltStu.addContent(eltAge);

            // 为<student>元素设置属性sn，值为03
            eltStu.setAttribute("sn", "03");

            Element root = doc.getRootElement();
            root.addContent(eltStu);

            // ---------------- 删除节点 -------------------
            root.removeChild("student");

            // ---------------- 修改节点 -------------------
            root.getChild("student").getChild("age").setText("22");
            XMLOutputter xmlOut = new XMLOutputter();
            Format fmt = Format.getPrettyFormat();
            fmt.setEncoding("utf-8");
            fmt.setIndent("    ");
            xmlOut.setFormat(fmt);
            xmlOut.output(doc,System.out);
        } catch(IOException e) {
            System.out.println(e.getMessage());
        } catch(JDOMException e) {
            System.out.println(e.getMessage());
        }
    }
}
