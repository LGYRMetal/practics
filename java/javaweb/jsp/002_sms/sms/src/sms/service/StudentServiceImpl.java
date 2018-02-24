package sms.service;

import sms.beans.Student;
import sms.dao.IStudentDao;
import sms.dao.StudentDaoImpl;
import sms.service.IStudentService;

public class StudentServiceImpl implements IStudentService {
	private IStudentDao dao;

	public StudentServiceImpl() {
		dao = new StudentDaoImpl();
	}

	@Override
	public Student checkUser(String num, String password) {
		return dao.selectStudentByLogin(num, password);
	}

	@Override
	public Integer saveStudent(Student student) {
		return dao.insertStudent(student);
	}

}
