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
		// 1. �����������������ȡSession
		String num = request.getParameter("num");
		String password = request.getParameter("password");
		HttpSession session = request.getSession();
		
		if(num == null || "".equals(num.trim())) {
			session.setAttribute("message", "ѧ�Ų���Ϊ��");
			response.sendRedirect(request.getContextPath() + "/login.jsp");
			return;
		}
		
		if(password == null || "".equals(password)) {
			session.setAttribute("message", "���벻��Ϊ��");
			response.sendRedirect(request.getContextPath() + "/login.jsp");
			return;
		}
		
		// 2. ����Service����
		IStudentService service = new StudentServiceImpl();

		// 3. ����Service�����checkUser()������֤��¼��Ϣ
		Student student = service.checkUser(num, password);
		
		// 4. ��֤δͨ���� ����ת����¼ҳ�棬���û��ٴ������¼��Ϣ�����Ҵ�ʱ��Ҫ���û�һЩ
		//    ��ʾ��Ϣ
		if(student == null) {
			session.setAttribute("message", "ѧ�Ż��������");
			response.sendRedirect(request.getContextPath() + "/login.jsp");
			return;
		}
		
		// 5. ��֤ͨ��������ת��ϵͳ��ҳ�� index.jsp
		session.setAttribute("student", student);
		response.sendRedirect(request.getContextPath() + "/welcome.jsp");
	}

}
