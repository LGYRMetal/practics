package com.lgy.jsp.tags;

import java.utils.List;
import java.utils.ArrayList;

public class CustomForEachListTag extends SimpleTagSupport {
    private List<String> items;
    private String var;

    public void setItems(List<String> items) {
        this.items = items;
    }

    public void setVar(String var) {
        this.var = var;
    }

    void doTag() {
        for(this.var : this.items) {
        }
    }
}
