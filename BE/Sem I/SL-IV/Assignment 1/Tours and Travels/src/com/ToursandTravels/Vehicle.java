package com.ToursandTravels;

public class Vehicle {
	private String vehicleNumber;
	private String vehicleModel;
	private String vehicleType;
	private int vehicleCapacity;
	
	public Vehicle() {
		super();
		// TODO Auto-generated constructor stub
	}

	public Vehicle(String vehicleNumber, String vehicleModel, String vehicleType, int vehicleCapacity) {
		super();
		this.vehicleNumber = vehicleNumber;
		this.vehicleModel = vehicleModel;
		this.vehicleType = vehicleType;
		this.vehicleCapacity = vehicleCapacity;
	}

	public int getVehicleCapacity() {
		return vehicleCapacity;
	}

	public String getVehicleModel() {
		return vehicleModel;
	}

	public String getVehicleNumber() {
		return vehicleNumber;
	}

	public String getVehicleType() {
		return vehicleType;
	}

	public void setVehicleCapacity(int vehicleCapacity) {
		this.vehicleCapacity = vehicleCapacity;
	}

	public void setVehicleModel(String vehicleModel) {
		this.vehicleModel = vehicleModel;
	}

	public void setVehicleNumber(String vehicleNumber) {
		this.vehicleNumber = vehicleNumber;
	}

	public void setVehicleType(String vehicleType) {
		this.vehicleType = vehicleType;
	}

	@Override
	public String toString() {
		return "Vehicle [vehicleNumber=" + vehicleNumber + ", vehicleModel=" + vehicleModel + ", vehicleType="
				+ vehicleType + ", vehicleCapacity=" + vehicleCapacity + "]";
	}
	

}
