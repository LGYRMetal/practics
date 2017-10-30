import java.awt.Button;
import java.awt.Frame;
import java.awt.FlowLayout;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.Toolkit;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Test {
    // Field
    Button button;
    Frame frame;
    TextArea textArea;
    TextField textField;

    // Constructor
    public Test() {
        init();
    }

    // Main Method
    public static void main(String[] args) {
        new Test();
    }

    // Method
    private void init() {
        // Create component
        button    = new Button("转到");
        frame     = new Frame();
        textArea  = new TextArea(40, 120);
        textField = new TextField(80);

        // Set component parameters

        // Frame
        // == Start == Get the Screen Size
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        int screenHeight = toolkit.getScreenSize().height;
        int screenWidth  = toolkit.getScreenSize().width;
        // == End ==== Get the Screen Size

        // Compute the x, y, width, height, when the frame at the center of
        // the Screen, and the height is 300, the width is 400.
        int frameHeight = 600;
        int frameWidth  = 800;
        int x = (screenWidth-frameWidth)/2;
        int y = (screenHeight-frameHeight)/2;
        frame.setBounds(x, y, frameWidth, frameHeight);
        frame.setLayout(new FlowLayout());
        frame.setVisible(true);

        // Add component to frame 
        frame.add(textField);
        frame.add(button);
        frame.add(textArea);

        // Register event
        event();
    }

    private void event() {
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
