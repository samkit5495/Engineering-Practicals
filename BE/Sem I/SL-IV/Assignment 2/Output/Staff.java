package com.ToursandTravels;

public abstract class Staff 
{
	protected String name;
	protected double salary;
	protected String mobileNo;
	protected int age;
	protected String gender;
	
	public Staff() {
		super();
		// TODO Auto-generated constructor stub
	}

	public Staff(String name, double salary, String mobileNo, int age, String gender) {
		super();
		this.name = name;
		this.salary = salary;
		this.mobileNo = mobileNo;
		this.age = age;
		this.gender = gender;
	}

	abstract public double calculateSalary(double attendence);

	public int getAge() {
		return age;
	}

	public String getGender() {
		return gender;
	}

	public String getMobileNo() {
		return mobileNo;
	}

	public String getName() {
		return name;
	}

	public double getSalary() {
		return salary;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public void setMobileNo(String mobileNo) {
		this.mobileNo = mobileNo;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	@Override
	public String toString() {
		return "Staff [name=" + name + ", salary=" + salary + ", mobileNo=" + mobileNo + ", age=" + age + ", gender="
				+ gender + "]";
	}
}
