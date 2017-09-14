import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class OutputInfo extends HttpServlet {
    public void doGet(HttpServletRequest, req, HttpServletResponse resp)
        throws ServletException, IOException {
        resp.setContentTpye("text/html; charset=UTF-8");
    }
}
