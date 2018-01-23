import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.*;
import javax.servlet.http.*;

public class WelcomeYou extends HttpServlet {
    public void doGet(HttpServletRequest req, HttpServletResponse resp)
        throws ServletException, IOException {
        String user = req.getParameter("user");
        String welcomeInfo = "Welcome you, " + user;

        req.setCharacterEncoding("UTF-8");
        //resp.setContentType("text/html");
        //resp.setCharacterEncoding("UTF-8");
        resp.setContentType("application/x-www-form-urlencoded; charset=UTF-8");

        PrintWriter out = resp.getWriter();
        out.println("<!DOCTYPE html>");
        out.println("<html>");
        out.println("\t<head>");
        out.println("\t\t<title>Welcome Page</title>");
        out.println("\t</head>");
        out.println("\t<body>");
        out.println("\t\t" + welcomeInfo);
        out.print("\t\t<p>请求:" + req.getCharacterEncoding());
        out.println("\t" + req.getContentType());
        out.println("\t\t<p>响应:" + resp.getCharacterEncoding());
        out.println("\t</body>");
        out.println("</html>");
        
        out.close();
    }

    public void doPost(HttpServletRequest req, HttpServletResponse resp)
        throws ServletException, IOException {
        doGet(req, resp);
    }
}
