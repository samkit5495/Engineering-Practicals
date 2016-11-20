package com.ToursandTravels;

import java.util.Date;
import java.util.LinkedList;

public class Customer 
{
	private String name;
	private String address;
	private String mobileNo;
	private int age;
	private String gender;
	private LinkedList<Bill> billList=null;
	
	public Customer() {
		super();
		// TODO Auto-generated constructor stub
		this.billList=new LinkedList<>();
	}

	public Customer(String name, String address, String mobileNo, int age, String gender) {
		super();
		this.name = name;
		this.address = address;
		this.mobileNo = mobileNo;
		this.age = age;
		this.gender = gender;
		this.billList=new LinkedList<>();
	}

	public String getAddress() {
		return address;
	}

	public int getAge() {
		return age;
	}

	public LinkedList<Bill> getBillList() {
		return billList;
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

	public Bill newBill(Plan p)
	{
		Bill b =new Bill();
		b.setDate(new Date());
		b.setSelectedPlan(p);
		p.newUsingCustomer(this);
		this.billList.add(b);
		return b;
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

	public void viewBills()
	{
		for(Bill b:this.getBillList())
			System.out.println(b);
	}
}
