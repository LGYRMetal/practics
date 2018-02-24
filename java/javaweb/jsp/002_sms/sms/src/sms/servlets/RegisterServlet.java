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

@WebServlet("/registerServlet")
public class RegisterServlet extends HttpServlet {
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		
		// 1. 获取session
		HttpSession session = request.getSession();
		
		// 2. 获取请求参数
		String num = request.getParameter("num"); // 不能为空
		String password = request.getParameter("password"); // 不能为空
		String name = request.getParameter("name"); // 不能为空
		String age = request.getParameter("age"); // 可以为空
		String score = request.getParameter("score"); // 可以为空
		
		if(num == null || "".equals(num.trim())) {
			session.setAttribute("message", "学号不能为空");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		if(password == null || "".equals(password)) {
			session.setAttribute("message", "密码不能为空");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		if(name == null || "".equals(name.trim())) {
			session.setAttribute("message", "姓名不能为空");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		if(age == null || "".equals(age.trim())) {
			session.setAttribute("message", "年龄不能为空");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		if(score == null || "".equals(score.trim())) {
			session.setAttribute("message", "成绩不能为空");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}

		//解决name可能出现的中文乱码问题
		byte[] bytes=name.getBytes("ISO8859-1");
		name = new String(bytes, "UTF-8");
		
		// 3. 创建Student对象
		Student student = new Student(num, name, Integer.valueOf(age), Double.valueOf(score));
		student.setPassword(password);
		
		// 4. 创建Service对象
		IStudentService service = new StudentServiceImpl();
		
		// 5. 调用Service对象的saveStudent()方法将对象写入DB
		Integer id = service.saveStudent(student);
		
		// 6. 写入失败， 则跳转到注册页面，重新注册，并给出错误信息
		if (id == null) {
			session.setAttribute("message", "数据写入数据库失败，请重试");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		// 7. 写入成功，则跳转到登录页面
		session.setAttribute("message", id);
		response.sendRedirect(request.getContextPath() + "/login.jsp");
		return;
	}

}
