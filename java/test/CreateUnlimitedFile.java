import java.io.FileOutputStream;

public class CreateUnlimitedFile {
    public static void main(String[] args) {
        // 创建字节输出流
        FileOutputStream fos = null;
        try {
            fos = new FileOutputStream("temp", true);

            // 向输出流写入数据
            while(true) {
                fos.write(1024*1024*1024);
            }
        } catch(Exception e) {
        } finally {
            if(fos != null) {
                try {fos.close();} catch(Exception e) {}
            }
        }
    }
}
