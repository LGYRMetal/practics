package sms.dao;

import sms.beans.Student;

public interface IStudentDao {

	public abstract Student selectStudentByLogin(String num, String password);

	public abstract Integer insertStudent(Student student);

}
