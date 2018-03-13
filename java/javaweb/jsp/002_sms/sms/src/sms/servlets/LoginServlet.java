package sms.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import sms.beans.Student;
import sms.service.IStudentService;
import sms.service.StudentServiceImpl;

@WebServlet("/loginServlet")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// 1. 接收请求参数，并获取Session
		String num = request.getParameter("num");
		String password = request.getParameter("password");
		HttpSession session = request.getSession();
		
		if(num == null || "".equals(num.trim())) {
			session.setAttribute("message", "学号不能为空");
			response.sendRedirect(request.getContextPath() + "/login.jsp");
			return;
		}
		
		if(password == null || "".equals(password)) {
			session.setAttribute("message", "密码不能为空");
			response.sendRedirect(request.getContextPath() + "/login.jsp");
			return;
		}
		
		// 2. 创建Service对象
		IStudentService service = new StudentServiceImpl();

		// 3. 调用Service对象的checkUser()方法验证登录信息
		Student student = service.checkUser(num, password);
		
		// 4. 验证未通过， 则跳转到登录页面，让用户再次输入登录信息，并且此时需要给用户一些
		//    提示信息
		if(student == null) {
			session.setAttribute("message", "学号或密码错误");
			response.sendRedirect(request.getContextPath() + "/login.jsp");
			return;
		}
		
		// 5. 验证通过，则跳转到系统主页面 index.jsp
		session.setAttribute("student", student);
		response.sendRedirect(request.getContextPath() + "/welcome.jsp");
	}

}
