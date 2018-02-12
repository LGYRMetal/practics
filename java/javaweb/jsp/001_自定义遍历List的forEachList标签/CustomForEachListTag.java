package com.lgy.jsp.tags;

import java.io.IOException;

import javax.servlet.jsp.JspException;

import java.utils.List;
import java.utils.ArrayList;


public class CustomForEachListTag extends SimpleTagSupport {
    private List<String> items;
    private String var; // 当前遍历对象要放入域中的属性名

    public void setItems(List<String> items) {
        this.items = items;
    }

    public void setVar(String var) {
        this.var = var;
    }

    void doTag() throws JspException, IOException {
        for(Object obj : this.items) {
            // 由于EL只能处理四大域中的数据，所以这里将当前遍历对象放入到
            // page域中，其key为var所指定的名称，而value则为当前的遍历对象
            // obj
            this.getJspContext().setAttribute(var, obj);
            this.getJspBody().invoke(null);
        }
    }
}
