import java.io.FileReader;
import java.io.IOException;

class test {
    public static void main(String[] args) throws IOException {
        int c;
        //FileReader fr = null;
        try (FileReader fr = new FileReader("students.xml")) {
            while((c = fr.read()) >= 0) {
                System.out.print((char)c);
            }
        } catch (IOException e) {
            e.printStackTrace();
        //} finally {
        //    fr.close();
        }
    }
}
