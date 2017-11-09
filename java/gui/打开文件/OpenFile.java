package com.lgyrmetal;

import java.awt.Toolkit;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import java.io.File;

import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JTextArea;

public class OpenFile extends JFrame {
    // Field
    JMenu menu;
    JMenuBar menuBar;
    JMenuItem fileOpen,
              fileSave,
              quit;
    JTextArea textArea;

    // Constructor
    public OpenFile() {
        init();
    }

    // Method
    private void init() {
        // Create components
        menu = new JMenu("文件(F)");
        menuBar = new JMenuBar();
        fileOpen = new JMenuItem("打开(O)");
        fileSave = new JMenuItem("保存(S)");
        quit = new JMenuItem("退出(Q)");
        textArea = new JTextArea();

        // Get the screen size
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        int screenWidth = toolkit.getScreenSize().width;
        int screenHeight = toolkit.getScreenSize().height;

        // Set components
        //// Set Menu
        menu.add(fileOpen);
        menu.add(fileSave);
        menu.add(quit);

        //// Set MenuBar
        menuBar.add(menu);

        //// Set Frame
        int frameWidth = 800;
        int frameHeight = 600;
        ////// Let the frame at the center of the screen
        int x = (screenWidth - frameWidth) / 2;
        int y = (screenHeight - frameHeight) / 2;
        setBounds(x, y, frameWidth, frameHeight);
        setJMenuBar(menuBar);

        ////// Add textArea to Frame
        add(textArea);

        setVisible(true);

        event();
    }

    private void event() {
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        fileOpen.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileChooser = new JFileChooser();
                fileChooser.showOpenDialog(null);

                fileChooser.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        File selectedFile = fileChooser.getSelectedFile();
                        try(BufferedReader br =
                                new BufferedReader(
                                    new InputStreamReader(
                                        new FileInputStream(
                                            selectedFile)))) {
                                            }
                    }
                });
            }
        });
    }

    public static void main(String[] args) {
        new OpenFile();
    }
}
