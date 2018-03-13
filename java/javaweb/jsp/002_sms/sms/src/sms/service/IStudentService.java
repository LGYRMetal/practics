package sms.service;

import sms.beans.Student;

public interface IStudentService {
	// 对用户登录信息进行验证
	public abstract Student checkUser(String num, String password);

	public abstract Integer saveStudent(Student student);
}
