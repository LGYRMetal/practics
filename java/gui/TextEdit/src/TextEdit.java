package com.lgyrmetal.TextEdit;

import java.awt.CardLayout;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.TextArea;
import java.awt.Toolkit;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class TextEdit extends Frame {
    // Field
    MenuBar menuBar;
    TextArea textArea;

    // Constructor
    public TextEdit() {
        init();
    }

    public TextEdit(String title) {
        super(title);
        init();
    }

    // Method
    private void init() {
        // Create components
        menuBar = new MenuBar();
        textArea = new TextArea("", 24, 80, TextArea.SCROLLBARS_NONE);

        // Set components parameters
        // Set Frame
        //     use to get screen size
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension screenSize = toolkit.getScreenSize();
        int frameWidth = 800;
        int frameHeight = 600;
        //     let the frame at the center of the screen
        int x = (screenSize.width - frameWidth) / 2;
        int y = (screenSize.height - frameHeight) / 2;
        setBounds(x, y, frameWidth, frameHeight);
        setLayout(new CardLayout());
        setVisible(true);

        // Add components to main frame
        setMenuBar(menuBar);
        add(textArea);
        add(new TextArea());

        event();
    }

    private void event() {
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        new TextEdit("无标题文档1 - TextEdit");
    }
}
