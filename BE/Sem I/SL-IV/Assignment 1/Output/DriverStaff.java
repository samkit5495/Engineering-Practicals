package com.ToursandTravels;

import java.util.List;

public class DriverStaff extends Staff
{
	private List<String> licenseNo;
	private int daysWorking;
	private final double workingSalary=1000;
	private final double notWorkingSalary=700;
	public DriverStaff() {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	public double calculateSalary(double cost) {
		return (daysWorking*workingSalary)+((30-daysWorking)-notWorkingSalary);
	}

	public int getDaysWorking() {
		return daysWorking;
	}

	public List<String> getLicenseNo() {
		return licenseNo;
	}

	public double getNotWorkingSalary() {
		return notWorkingSalary;
	}

	public double getWorkingSalary() {
		return workingSalary;
	}

	public void setDaysWorking(int daysWorking) {
		this.daysWorking = daysWorking;
	}

	public void setLicenseNo(List<String> licenseNo) {
		this.licenseNo = licenseNo;
	}

	@Override
	public String toString() {
		return "DriverStaff [licenseNo=" + licenseNo + ", daysWorking=" + daysWorking + ", workingSalary="
				+ workingSalary + ", notWorkingSalary=" + notWorkingSalary + "]";
	}
}
