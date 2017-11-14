package com.lgyrmetal;

import java.awt.Component;
import java.awt.Container;
import java.awt.Font;
import java.awt.Toolkit;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;

import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.KeyStroke;

public class OpenFile extends JFrame {
    // Field
    private File openedFile;
    private JMenu menu;
    private JMenuBar menuBar;
    private JMenuItem fileOpen,
                      fileSave,
                      quit;
    private JScrollPane scrollPane;
    private JTextArea textArea;

    // Constructor
    public OpenFile() {
        init();
    }

    // Method
    private void init() {
        // Create components
        menu = new JMenu("文件(F)");
        menuBar = new JMenuBar();
        fileOpen = new JMenuItem("打开(O)", KeyEvent.VK_O);
        fileSave = new JMenuItem("保存(S)", KeyEvent.VK_S);
        quit = new JMenuItem("退出(Q)", KeyEvent.VK_Q);
        textArea = new JTextArea();
        scrollPane = new JScrollPane(textArea);

        // Get the screen size
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        int screenWidth = toolkit.getScreenSize().width;
        int screenHeight = toolkit.getScreenSize().height;

        // Set components
        //// Set MenuItem
        //fileOpen.setFont(new Font("Serif", Font.PLAIN, 15));
        //fileSave.setFont(new Font("Serif", Font.PLAIN, 15));
        //quit.setFont(new Font("Serif", Font.PLAIN, 15));
        fileOpen.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O,
                    ActionEvent.CTRL_MASK));
        fileSave.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S,
                    ActionEvent.CTRL_MASK));
        quit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_Q,
                    ActionEvent.CTRL_MASK));

        //// Set Menu
        //menu.setFont(new Font("Serif", Font.PLAIN, 15));
        menu.setMnemonic(KeyEvent.VK_F);
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
        setTitle("无标题文档");

        ////// Add textArea to Frame
        add(scrollPane);
        setAllFont(this, new Font("Serif", Font.PLAIN, 15));

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
                setAllFont(fileChooser, new Font("Serif", Font.PLAIN, 15));
                //fileChooser.setFont(new Font("Serif", Font.PLAIN, 15));
                int returnVal = fileChooser.showOpenDialog(OpenFile.this);

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
                    OpenFile.this.openedFile = selectedFile;
                }
                    //}
                //});
            }
        });

        fileSave.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if(!OpenFile.this.openedFile) {
                    JFileChooser fileChooser = new JFileChooser();
                    setAllFont(fileChooser,
                               new Font("Serif", Font.PLAIN, 15));
                    int fcReturnValue =
                        fileChooser.showSaveDialog(OpenFile.this);

                    if(fcReturnValue == JFileChooser.APPROVE_OPTION) {
                        File saveFile = fileChooser.getSelectedFile();
                        Object[] options = {"替换(R)", "取消(C)"};
                        if(saveFile.exists()) {
                            int odReturnValue =
                                JOptionPane.showOptionDialog(
                                        fileChooser,
                                        "\"" + saveFile.getParent() +
                                        "\"已存在名为" +
                                        saveFile.getName() +
                                        "的文件。替换该文件将覆盖它的内" +
                                        "容。您想要替换它吗？", null,
                                        JOptionPane.YES_NO_OPTION,
                                        JOptionPane.WARNING_MESSAGE, null,
                                        options, options[1]
                                        );
                        } else {
                            writeTo(saveFile);
                            OpenFile.this.openedFile = saveFile;
                        }
                    }
                } else {
                    writeTo(OpenFile.this.openedFile);
                }
            }
        });

        quit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
    }

    private void setAllFont(Component comp, Font font) {
        if(comp instanceof Container) {
            //System.out.println(comp);
            Container container = (Container) comp;
            //int compCount = container.getComponentCount();
            Component[] compsInContainer = null;
            if(container instanceof JMenu) {
                compsInContainer = ((JMenu)container).getMenuComponents();
            }
            else {
                compsInContainer = container.getComponents();
            }

            for(Component c : compsInContainer) {
                //if(c instanceof JComponent) {
                    //System.out.println(c);
                //    ((JComponent)c).setFont(font);
                //}
                c.setFont(font);
                setAllFont(c, font);
            }
        } else {
            //System.out.println("===" + comp);
            comp.setFont(font);
        }
    }

    public static void main(String[] args) {
        new OpenFile();
    }
}
