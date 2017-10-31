import java.awt.Button;
import java.awt.Color;
import java.awt.Dialog;
import java.awt.Frame;
import java.awt.FlowLayout;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.Toolkit;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter; import java.awt.event.WindowEvent;

import java.io.File;

public class Test {
    ///// Field
    private Button button;
    private Frame frame;
    private TextArea textArea;
    private TextField textField;

    ///// Constructor
    public Test() {
        init();
    }

    ///// Main Method
    public static void main(String[] args) {
        new Test();
    }

    //// Method
    private void init() {
        //// Create component
        button    = new Button("转到");
        frame     = new Frame();
        textArea  = new TextArea(40, 120);
        textField = new TextField(114);

        //// Set component parameters
        /// Set Frame
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

        /// Set TextArea
        textArea.setEditable(false);
        textArea.setBackground(Color.WHITE);

        //// Add component to frame 
        frame.add(textField);
        frame.add(button);
        frame.add(textArea);

        //// Register event
        event();
    }

    private void event() {
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Clear the TextArea when click the Button first.
                textArea.setText("");

                String text = textField.getText();

                if("".equals(text)) {
                    //textArea.setText("请输入目录路径!");
                    return;
                }

                File f = new File(text);
                if(!f.exists()) {
                    textArea.setText("您输入的目录不存在!");
                } else if(!f.isDirectory()) {
                    textArea.setText("您输入的不是目录，请输入目录!");
                } else {
                    String[] list = f.list();
                    for(String item : list) {
                        textArea.append(item + "\n");
                    }
                }
            }
        });
    }

    private void showErrorDialog(
            Dialog  owner,
            String  title,
            boolean modal,
            String  msg) {
        // Create component used for ErrorDialog
        Button button = new Button("确定");
        Dialog dialog = new dialog(owner, "Test", modal);
        Lable   lable = new Lable(msg);
    }
}
