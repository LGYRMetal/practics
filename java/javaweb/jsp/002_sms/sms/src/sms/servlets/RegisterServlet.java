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
		
		// 1. ��ȡsession
		HttpSession session = request.getSession();
		
		// 2. ��ȡ�������
		String num = request.getParameter("num"); // ����Ϊ��
		String password = request.getParameter("password"); // ����Ϊ��
		String name = request.getParameter("name"); // ����Ϊ��
		String age = request.getParameter("age"); // ����Ϊ��
		String score = request.getParameter("score"); // ����Ϊ��
		
		if(num == null || "".equals(num.trim())) {
			session.setAttribute("message", "ѧ�Ų���Ϊ��");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		if(password == null || "".equals(password)) {
			session.setAttribute("message", "���벻��Ϊ��");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		if(name == null || "".equals(name.trim())) {
			session.setAttribute("message", "��������Ϊ��");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		if(age == null || "".equals(age.trim())) {
			session.setAttribute("message", "���䲻��Ϊ��");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		if(score == null || "".equals(score.trim())) {
			session.setAttribute("message", "�ɼ�����Ϊ��");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}

		//���name���ܳ��ֵ�������������
		byte[] bytes=name.getBytes("ISO8859-1");
		name = new String(bytes, "UTF-8");
		
		// 3. ����Student����
		Student student = new Student(num, name, Integer.valueOf(age), Double.valueOf(score));
		student.setPassword(password);
		
		// 4. ����Service����
		IStudentService service = new StudentServiceImpl();
		
		// 5. ����Service�����saveStudent()����������д��DB
		Integer id = service.saveStudent(student);
		
		// 6. д��ʧ�ܣ� ����ת��ע��ҳ�棬����ע�ᣬ������������Ϣ
		if (id == null) {
			session.setAttribute("message", "����д�����ݿ�ʧ�ܣ�������");
			response.sendRedirect(request.getContextPath() + "/register.jsp");
			return;
		}
		
		// 7. д��ɹ�������ת����¼ҳ��
		session.setAttribute("message", id);
		response.sendRedirect(request.getContextPath() + "/login.jsp");
		return;
	}

}
