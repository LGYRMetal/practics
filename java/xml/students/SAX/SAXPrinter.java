package SAX;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;

import javax.xml.parsers.*;
import org.xml.sax.*;
import org.xml.sax.helpers.DefaultHandler;

public class SAXPrinter extends DefaultHandler {
    public void startDocument() throws SAXException {
        char c;
        //FileReader fr = null;

        // 输出XML声明，不管是DOM还是SAX都不会对XML声明进行解析，所以，在这
        // 里从xml文档读出第一行，并输出
        try (FileReader fr = new FileReader("students.xml")) {
            while ((c = (char)fr.read()) != '\n') {
                System.out.print(c);
            }
            System.out.print(c);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void processingInstruction(String target, String data)
        throws SAXException {
        // 输出文档中的处理指令
        System.out.println("<?" + target + " " + data + "?>");
    }

    public void startElement(String uri, String localName, String qName,
            Attributes attrs) throws SAXException {
        // 输出元素的开始标签及属性
        System.out.print("<" + qName);
        int len = attrs.getLength();
        for (int i = 0; i < len; i++) {
            System.out.print(" ");
            System.out.print(attrs.getQName(i));
            System.out.print("=\"");
            System.out.print(attrs.getValue(i));
            System.out.print("\"");
        }
        System.out.print(">");
    }

    public void characters(char[] ch, int start, int length)
        throws SAXException {
        // 输出元素的字符数据内容
        System.out.print(new String(ch, start, length));
    }

    public void endElement(String uri, String localName, String qName)
        throws SAXException {
        // 输出元素的结束标签
        System.out.print("</" + qName + ">");
    }

    public static void main(String[] args) {
        SAXParserFactory spf = SAXParserFactory.newInstance();
        SAXParser sp = null;

        try {
            sp = spf.newSAXParser();
            File file = new File("students.xml");
            sp.parse(file, new SAXPrinter());
        } catch (ParserConfigurationException e) {
            e.printStackTrace();
        } catch (SAXException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
