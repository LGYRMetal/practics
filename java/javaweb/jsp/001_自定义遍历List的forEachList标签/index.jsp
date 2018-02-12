<%@ page pageEncoding="UTF-8" %>
<%@ page import="java.utils.List" %>
<%@ page import="java.utils.ArrayList" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>001_自定义遍历List的forEachList标签</title>
    </head>

    <body>
        <%
            List<String> names = new ArrayList<>();
            names.add("张三");
            names.add("李四");
            names.add("王五");

            pageContext.setAttribute("names", names);
        %>
        
        <ct:forEachList items="${names}" var="name">
            ${name} <br/>
        </ct:forEachList>
    </body>
</html>
