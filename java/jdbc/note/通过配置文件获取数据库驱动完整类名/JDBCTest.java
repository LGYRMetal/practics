import java.io.FileReader;
import java.util.Properties;
import oracle.jdbc.pool.*;

public class JDBCTest {
    public static void main(String[] args) {
        FileReader fr = null;
        Properties pro = null;
        // 通过 FileReader 读取配置文件
        try {
            fr = new FileReader("db.properties");

            // 创建一个属性对象
            pro = new Properties();

            // 通过属性对象的 load()方法 将 fr 读取到内存中生成一个 Map 集合
            pro.load(fr);
        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            // 关闭流
            if(fr != null) {
                try {
                    fr.close();
                } catch(Exception e) {
                    e.printStackTrace();
                }
            }
        }

        // 通过属性对象的 getProperty(String key) 方法获取数据库名称
        String dbname = pro.getProperty("dbname");

        JDBC jdbc = null;
        try {
        // 通过java的反射机制创建该类
        Class c = Class.forName(dbname);
        jdbc = (JDBC) c.newInstance();
        } catch(Exception e) {
            e.printStackTrace();
        }
        jdbc.getConnection();
    }
}
