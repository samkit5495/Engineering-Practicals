package com.ToursandTravels;

public class Customer 
{
	private String name;
	private String address;
	private String mobileNo;
	private int age;
	private String gender;
	
	public Customer() {
		super();
		// TODO Auto-generated constructor stub
	}

	public Customer(String name, String address, String mobileNo, int age, String gender) {
		super();
		this.name = name;
		this.address = address;
		this.mobileNo = mobileNo;
		this.age = age;
		this.gender = gender;
	}

	public String getAddress() {
		return address;
	}

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

	public void setAddress(String address) {
		this.address = address;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void setGender(String gender) {
		if(gender=="Male"||gender=="Female")
			this.gender = gender;
		else
			System.out.println("Wrong Gender Format!!!");
	}

	public void setMobileNo(String mobileNo) {
		this.mobileNo = mobileNo;
	}

	

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return "Customer [name=" + name + ", address=" + address + ", mobileNo=" + mobileNo + ", age=" + age
				+ ", gender=" + gender + "]";
	}
}
