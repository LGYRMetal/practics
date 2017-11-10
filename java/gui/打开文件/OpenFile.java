package com.lgyrmetal;

import java.awt.Font;
import java.awt.Toolkit;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;

import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class OpenFile extends JFrame {
    // Field
    JMenu menu;
    JMenuBar menuBar;
    JMenuItem fileOpen,
              fileSave,
              quit;
    JScrollPane scrollPane;
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
        scrollPane = new JScrollPane(textArea);

        // Get the screen size
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        int screenWidth = toolkit.getScreenSize().width;
        int screenHeight = toolkit.getScreenSize().height;

        // Set components
        //// Set MenuItem
        fileOpen.setFont(new Font("Serif", Font.PLAIN, 15));
        fileSave.setFont(new Font("Serif", Font.PLAIN, 15));
        quit.setFont(new Font("Serif", Font.PLAIN, 15));

        //// Set Menu
        menu.setFont(new Font("Serif", Font.PLAIN, 15));
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
        setFont(new Font("Serif", Font.PLAIN, 15));
        setJMenuBar(menuBar);
        setTitle("无标题文档");

        ////// Add textArea to Frame
        add(scrollPane);

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
                //fileChooser.setFont(new Font("Serif", Font.PLAIN, 15));
                int returnVal = fileChooser.showOpenDialog(null);

                //fileChooser.addActionListener(new ActionListener() {
                    //public void actionPerformed(ActionEvent e) {
                if(returnVal == JFileChooser.APPROVE_OPTION) {
                    // clean the textArea first when open a file
                    textArea.setText(null);

                    // used to avoid the last empty line
                    String currentLine = null,
                           previousLine = null;
                    File selectedFile = fileChooser.getSelectedFile();
                    try(BufferedReader br =
                            new BufferedReader(
                                new InputStreamReader(
                                    new FileInputStream(selectedFile)))) {
                        // used to avoid the last empty line
                        if((previousLine = br.readLine()) == null)
                            return;
                        while((currentLine = br.readLine()) != null) {
                            // used to avoid the last empty line
                            textArea.append(previousLine + "\n");
                            previousLine = currentLine;
                        }
                        // used to avoid the last empty line
                        textArea.append(previousLine);
                    } catch(Exception exception) {
                        exception.printStackTrace();
                    }
                    // set the window title to the opened file's title
                    setTitle(selectedFile.getName());
                }
                    //}
                //});
            }
        });
    }

    public static void main(String[] args) {
        new OpenFile();
    }
}
