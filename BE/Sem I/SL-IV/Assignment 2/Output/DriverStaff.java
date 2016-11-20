package com.ToursandTravels;

import java.util.LinkedList;
import java.util.List;

public class DriverStaff extends Staff
{
	private LinkedList<String> licenseNoList;
	public DriverStaff() {
		super();
		// TODO Auto-generated constructor stub
		licenseNoList=new LinkedList<>();
	}

	@Override
	public double calculateSalary(double attendence) {
		return (attendence*salary)+((30-attendence)*(salary*0.03));
	}

	public List<String> getLicenseNo() {
		return licenseNoList;
	}

	public void newLicense(String s)
	{
		this.licenseNoList.add(s);
	}
	public void showLicenses()
	{
		if(licenseNoList.size()==0)
		{
			System.out.println("No License Added");
			return;
		}
		for(String s:licenseNoList)
			System.out.println(s);
	}
	@Override
	public String toString() {
		return "DriverStaff [licenseNoList=" + licenseNoList + ", name=" + name + ", salary=" + salary + ", mobileNo="
				+ mobileNo + ", age=" + age + ", gender=" + gender + "]";
	}
}
