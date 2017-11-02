package com.lgyrmetal.TextEdit;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Dialog;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Label;
import java.awt.Panel;
import java.awt.Window;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class ErrorDialog extends Dialog {
    // Field
    private Button button;
    private Label  label;
    private Panel  panel;

    // Constructor
    public ErrorDialog(Dialog owner, String title, boolean modal) {
        this(owner, title, modal, "确定", "您的操作出现错误,请检查错误！");
    }

    public ErrorDialog(Dialog owner, String title, boolean modal,
            String buttonText, String errMsg) {
        super(owner, title, modal);
        init(owner, buttonText, errMsg);
    }

    public ErrorDialog(Frame owner, String title, boolean modal) {
        this(owner, title, modal, "确定", "您的操作出现错误,请检查错误！");
    }

    public ErrorDialog(Frame owner, String title, boolean modal,
            String buttonText, String errMsg) {
        super(owner, title, modal);
        init(owner, buttonText, errMsg);
    }

    public ErrorDialog(Window owner, String title) {
        this(owner, title, "确定", "您的操作出现错误,请检查错误！");
    }

    public ErrorDialog(Window owner, String title,
            String buttonText, String errMsg) {
        super(owner, title);
        init(owner, buttonText, errMsg);
    }

    private void init(Window owner, String buttonText, String errMsg) {
        //// Initialize the component
        button = new Button(buttonText);
        label  = new Label(errMsg, Label.CENTER);
        panel  = new Panel(new FlowLayout());

        //// Set parameters of component
        /// Set ErrorDialog
        int dialogWidth  = getStringWidth(errMsg);
        int dialogHeight = 60;
        int x = owner.getX() + (owner.getWidth() - dialogWidth) / 2;
        int y = owner.getY() + (owner.getHeight() - dialogHeight) / 2;
        setBounds(x, y, dialogWidth, dialogHeight);
        /*
        setLayout(new FlowLayout(FlowLayout.CENTER,
                    10000, // 这样，即使文本很长也能让按钮在下一行,下面使用
                           // BorderLayout解决更好
                    6));
        */
        setLayout(new BorderLayout());
        setResizable(false);
        // 使用BorderLayout就不用这个了
        //setMinimumSize(new Dimension(100, 60));

        //// Add Button to Panel
        panel.add(button);

        //// Add Panel and Label to ErrorDialog
        add(label, BorderLayout.NORTH);
        add(panel, BorderLayout.SOUTH);

        //// Register event
        event();
    }

    private void event() {
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                setVisible(false);
            }
        });

        button.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                if(e.getKeyCode() == KeyEvent.VK_ENTER ||
                        e.getKeyCode() == KeyEvent.VK_ESCAPE) {
                    setVisible(false);
                }
            }
        });

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                setVisible(false);
            }
        });
    }

    private int getStringWidth(String str) {
        return str.getBytes().length * 6;
    }
}
