package com.lgyrmetal.TextEdit;

import java.awt.Button;
import java.awt.MenuItem;
import java.awt.MenuShortcut;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class FileMenuItemNewTag extends MenuItem {
    // Field
    TextEdit textEdit;

    // Constructor
    public FileMenuItemNewTag(TextEdit textEdit) {
        super();
        this.textEdit = textEdit;
        init();
    }

    public FileMenuItemNewTag(TextEdit textEdit, String label) {
        super(label);
        this.textEdit = textEdit;
        init();
    }

    public FileMenuItemNewTag(TextEdit textEdit, String label,
            MenuShortcut s) {
        super(label, s);
        this.textEdit = textEdit;
        init();
    }

    // Method
    private void init() {
        event();
    }

    private void event() {
        addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textEdit.bottomPanel.add(new Button("oo"));
            }
        });
    }
}
