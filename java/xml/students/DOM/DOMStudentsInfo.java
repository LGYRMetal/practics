package DOM;

import java.io.File;
import java.io.IOException;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.*;
import org.xml.sax.SAXException;

public class DOMStudentsInfo {
    public static void main(String[] args) {
        DocumentBuilderFactory dbf=DocumentBuilderFactory.newInstance();
        System.out.println("解析器工厂类: " + dbf.getClass().getName());
        try {
            DocumentBuilder db=dbf.newDocumentBuilder();
            System.out.println("解析器类名: " + db.getClass().getName());
            File file=new File("students.xml");
            Document doc=db.parse(file);

            NodeList nl=doc.getElementsByTagName("student");

            int len=nl.getLength();
            for(int i=0; i<len; i++) {
                Element eltStu=(Element)nl.item(i);
                Node eltName=eltStu.getElementsByTagName("name").item(0);
                Node eltAge=eltStu.getElementsByTagName("age").item(0);
                
                String name=eltName.getFirstChild().getNodeValue();
                String age=eltAge.getFirstChild().getNodeValue();

                System.out.print("姓名: ");
                System.out.println(name);
                System.out.print("年龄: ");
                System.out.println(age);
                System.out.println("--------------------------------");
            }
        } catch(ParserConfigurationException e) {
            e.printStackTrace();
        } catch(SAXException e) {
            e.printStackTrace();
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}
