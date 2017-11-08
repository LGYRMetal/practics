package com.lgyrmetal.TextEdit;

import java.awt.Menu;

public class MenuBar extends java.awt.MenuBar {
    // Field
    TextEdit textEdit;

    Menu mainMenuFile;
    Menu mainMenuEdit;
    Menu mainMenuView;
    Menu mainMenuSearch;
    Menu mainMenuTool;
    Menu mainMenuDocument;
    Menu mainMenuHelp;

    // Constructor
    public MenuBar(TextEdit textEdit) {
        this(
                textEdit,
                new MainMenuFile(textEdit, "文件(F)", true),
                new MainMenuEdit("编辑(E)"),
                new MainMenuView("查看(V)"),
                new MainMenuSearch("搜索(S)"),
                new MainMenuTool("工具(T)"),
                new MainMenuDocument("文档(D)"),
                new MainMenuHelp("帮助(H)")
                );
    }

    public MenuBar(
            TextEdit textEdit,
            Menu mainMenuFile,
            Menu mainMenuEdit,
            Menu mainMenuView,
            Menu mainMenuSearch,
            Menu mainMenuTool,
            Menu mainMenuDocument,
            Menu mainMenuHelp) {
        this.textEdit = textEdit;
        this.mainMenuFile = mainMenuFile;
        this.mainMenuEdit = mainMenuEdit;
        this.mainMenuView = mainMenuView;
        this.mainMenuSearch = mainMenuSearch;
        this.mainMenuTool = mainMenuTool;
        this.mainMenuDocument = mainMenuDocument;
        this.mainMenuHelp = mainMenuHelp;

        add(mainMenuFile);
        add(mainMenuEdit);
        add(mainMenuView);
        add(mainMenuSearch);
        add(mainMenuTool);
        add(mainMenuDocument);
        add(mainMenuHelp);
        //setHelpMenu(mainMenuHelp);
    }
}
