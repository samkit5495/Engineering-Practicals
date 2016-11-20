package com.ToursandTravels;

public class WorkingStaff extends Staff
{
	private String designation;
	@Override
	public double calculateSalary(double attendence) {
		// TODO Auto-generated method stub
		return attendence*(salary/31);
		
	}

	public String getDesignation() {
		return designation;
	}

	public void setDesignation(String designation) {
		this.designation = designation;
	}

	@Override
	public String toString() {
		return "WorkingStaff [designation=" + designation + ", name=" + name + ", salary=" + salary + ", mobileNo="
				+ mobileNo + ", age=" + age + ", gender=" + gender + "]";
	}
	
}
