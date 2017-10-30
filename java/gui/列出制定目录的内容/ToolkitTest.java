import java.awt.Toolkit;

public class ToolkitTest {
    public static void main(String[] args) {
        Toolkit toolkit = Toolkit.getDefaultToolkit();

        System.out.println(toolkit);
        System.out.println("Screen Size: " + toolkit.getScreenSize());
        System.out.println("Screen Height: " + toolkit.getScreenSize().height);
        System.out.println("Screen width: " + toolkit.getScreenSize().width);
        System.out.println("Screen Height: " + toolkit.getScreenSize().getHeight());
        System.out.println("Screen Height: " + toolkit.getScreenSize().getWidth());
    }
}
