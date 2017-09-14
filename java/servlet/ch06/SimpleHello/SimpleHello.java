import javax.servlet.http.*;
import javax.servlet.ServletException;
import java.io.*;

public class SimpleHello extends HttpServlet {
    public void doGet(HttpServletRequest req, HttpServletResponse resp)
        throws ServletException, IOException {
        // 得到PrintWriter对象
        PrintWriter out = resp.getWriter();

        // 向客户端方法送字符数据
        out.println("Hello World");
        out.close();
    }
}
