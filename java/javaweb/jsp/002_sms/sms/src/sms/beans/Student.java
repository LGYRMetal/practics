package sms.beans;

import java.io.Serializable;

public class Student implements Serializable {
	private Integer id; // 业务无关主键，如果id是要声明为int类型，建议将它声明为包装类型
						// Integer，因为声明为Integer可以对id进行if(id == null)这样的
						// 判断，而int类型则不行
	private String num; // 学号
	private String password; // 登陆密码
	private String name;
	private int age;
	private double score;

	public Student() {
		super();
		// TODO Auto-generated constructor stub
	}

	public Student(String num, String name, int age, double score) {
		super();
		this.num = num;
		this.name = name;
		this.age = age;
		this.score = score;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getNum() {
		return num;
	}

	public void setNum(String num) {
		this.num = num;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public double getScore() {
		return score;
	}

	public void setScore(double score) {
		this.score = score;
	}
}
