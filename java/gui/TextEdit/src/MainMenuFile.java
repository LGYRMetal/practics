package com.lgyrmetal.TextEdit;

import java.awt.Menu;
import java.awt.MenuItem;
import java.awt.MenuShortcut;

import java.awt.event.KeyEvent;

public class MainMenuFile extends Menu {
    // Field
    TextEdit textEdit;

    MenuItem fileMenuItemNewTag;        // 新建(T), 新建标签
    MenuItem fileMenuItemOpen;          // 打开(O)
    Menu     fileSubMenuRecentlyOpened; // 最精打开(R), 子菜单
    MenuItem fileMenuItemSave;          // 保存(S)
    MenuItem fileMenuItemSaveAs;        // 另存为(A)
    MenuItem fileMenuItemNewWindow;     // 新窗口(N)
    MenuItem fileMenuItemReload;        // 重新载入(R)
    MenuItem fileMenuItemPrint;         // 打印(P)
    MenuItem fileMenuItemClose;         // 关闭(C), 关闭当前标签，
                                        // 如果只有一个标签，则关闭窗口
    MenuItem fileMenuItemQuit;          // 退出(Q)

    // Construtor
    public MainMenuFile(TextEdit textEdit) {
        super();
        this.textEdit = textEdit;
        init();
    }

    public MainMenuFile(TextEdit textEdit, String label) {
        super(label);
        this.textEdit = textEdit;
        init();
    }

    public MainMenuFile(TextEdit textEdit, String label, boolean tearOff) {
        super(label, tearOff);
        this.textEdit = textEdit;
        init();
    }

    // Method
    private void init() {
        fileMenuItemNewTag = new FileMenuItemNewTag(textEdit, "新建(N)",
                new MenuShortcut(KeyEvent.VK_T));
        //MenuItem fileMenuItemOpen;          // 打开(O)
        //Menu     fileSubMenuRecentlyOpened; // 最精打开(R), 子菜单
        //MenuItem fileMenuItemSave;          // 保存(S)
        //MenuItem fileMenuItemSaveAs;        // 另存为(A)
        //MenuItem fileMenuItemNewWindow;     // 新窗口(N)
        //MenuItem fileMenuItemReload;        // 重新载入(R)
        //MenuItem fileMenuItemPrint;         // 打印(P)
        //MenuItem fileMenuItemClose;         // 关闭(C), 关闭当前标签，
        // 如果只有一个标签，则关闭窗口
        //MenuItem fileMenuItemQuit;          // 退出(Q)

        add(fileMenuItemNewTag);
    }
}
