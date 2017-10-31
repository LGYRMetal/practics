import java.awt.Button;
import java.awt.Dialog;
import java.awt.FlowLayout;
import java.awt.Label;

public class ErrorDialog extends Dialog {
    // Field
    private Button button;
    private Label  label;

    // Constructor
    public ErrorDialog(Dialog owner, String title, boolean modal) {
        this(owner, title, modal, "确定", "您的操作出现错误,请检查错误！");
    }

    public ErrorDialog(
            Dialog owner, String title, boolean modal,
            String buttonText, String errMsg) {
        //// Initialize the component
        super(owner, title, modal);
        button = new Button(buttonText);
        label  = new Label(errMsg);

        //// Set parameters of component
        /// Set ErrorDialog
        int dialogWidth  = label.getWidth() + 2;
        int dialogHeight = 40;
        int x = owner.getX + (owner.getWidth() - dialogWidth()) / 2;
        int y = owner.getY + (owner.getHeight() - dialogHeight()) / 2;
        setBounds(x, y, dialogWidth, dialogHight);
        setLayout(new FlowLayout());
        setVisible(true);

        /// Add Button and Label to ErrorDialog
        add(button);
        add(label);

        //// Register event
        event();
    }

    public ErrorDialog(Frame owner, String title, boolean modal) {
        this(owner, title, modal, "确定", "您的操作出现错误,请检查错误！");
    }

    public ErrorDialog(
            Dialog owner, String title, boolean modal,
            String buttonText, String errMsg) {
        //// Initialize the component
        super(owner, title, modal);
        button = new Button(buttonText);
        label  = new Label(errMsg);

        //// Set parameters of component
        /// Set ErrorDialog
        int dialogWidth  = label.getWidth() + 2;
        int dialogHeight = 40;
        int x = owner.getX + (owner.getWidth() - dialogWidth()) / 2;
        int y = owner.getY + (owner.getHeight() - dialogHeight()) / 2;
        setBounds(x, y, dialogWidth, dialogHight);
        setLayout(new FlowLayout());
        setVisible(true);

        /// Add Button and Label to ErrorDialog
        add(button);
        add(label);

        //// Register event
        event();
    }

    public ErrorDialog(Window owner, String title, boolean modal) {
        this(owner, title, modal, "确定", "您的操作出现错误,请检查错误！");
    }

    public ErrorDialog(
            Dialog owner, String title, boolean modal,
            String buttonText, String errMsg) {
        //// Initialize the component
        super(owner, title, modal);
        button = new Button(buttonText);
        label  = new Label(errMsg);

        //// Set parameters of component
        /// Set ErrorDialog
        int dialogWidth  = label.getWidth() + 2;
        int dialogHeight = 40;
        int x = owner.getX + (owner.getWidth() - dialogWidth()) / 2;
        int y = owner.getY + (owner.getHeight() - dialogHeight()) / 2;
        setBounds(x, y, dialogWidth, dialogHight);
        setLayout(new FlowLayout());
        setVisible(true);

        /// Add Button and Label to ErrorDialog
        add(button);
        add(label);

        //// Register event
        event();
    }
}
