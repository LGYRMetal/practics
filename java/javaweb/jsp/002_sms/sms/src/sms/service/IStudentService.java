package sms.service;

import sms.beans.Student;

public interface IStudentService {
	// ���û���¼��Ϣ������֤
	public abstract Student checkUser(String num, String password);

	public abstract Integer saveStudent(Student student);
}
