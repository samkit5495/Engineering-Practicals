package com.ToursandTravels;

public class WorkerStaff extends Staff
{
	private String designation;
	private int attendence;
	@Override
	public double calculateSalary(double cost) {
		// TODO Auto-generated method stub
		return attendence*cost;
		
	}

	public int getAttendence() {
		return attendence;
	}

	
	public String getDesignation() {
		return designation;
	}

	public void setAttendence(int attendence) {
		this.attendence = attendence;
	}

	public void setDesignation(String designation) {
		this.designation = designation;
	}
	
}
