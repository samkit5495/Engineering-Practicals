package com.ToursandTravels;

import java.util.Date;

public class Bill {

	private double billAmount;
	private Date date;
	private double paidAmount;
	private final float payableTaxPercent=5;
	
	public Bill(double billAmount, double paidAmount) {
		super();
		this.billAmount = billAmount;
		this.date = new Date();
		this.paidAmount = paidAmount;
	}
	public double getBillAmount() {
		return billAmount;
	}
	public Date getDate() {
		return date;
	}
	public double getPaidAmount() {
		return paidAmount;
	}
	public float getPayableTaxPercent() {
		return payableTaxPercent;
	}
	public void setBillAmount(double billAmount) {
		this.billAmount = billAmount;
	}
	public void setDate(Date date) {
		this.date = date;
	}
	public void setPaidAmount(double paidAmount) {
		this.paidAmount = paidAmount;
	}
}
