package com.ToursandTravels;

import java.util.Date;

public class Bill {

	private double billAmount;
	private Date date;
	private double paidAmount;
	private final double payableTaxPercent=0.05;
	private Plan selectedPlan=null;
	public Bill() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public Bill(double billAmount, double paidAmount, Plan selectedPlan) {
		super();
		this.billAmount = billAmount;
		this.date = new Date();
		this.paidAmount = paidAmount;
		this.selectedPlan = selectedPlan;
	}
	private double computeAmount()
	{
		return this.selectedPlan.getCost();
	}
	private double computeTax()
	{
		return this.selectedPlan.getCost()*this.payableTaxPercent;
	}
	private double computeTotalAmount()
	{
		this.billAmount=computeAmount()+computeTax();
		return this.billAmount;
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
	public double getPayableTaxPercent() {
		return payableTaxPercent;
	}
	public Plan getSelectedPlan() {
		return selectedPlan;
	}
	public void print(Customer c)
	{
		System.out.println("Date: "+date);
		System.out.println("Customer Name: "+c.getName());
		System.out.println("Mobile No: "+c.getMobileNo());
		System.out.println("____________________________________________________");
		System.out.println("Plan Details:");
		System.out.println("____________________________________________________");
		System.out.println("Source: "+this.selectedPlan.getSource());
		System.out.println("Destination: "+this.selectedPlan.getDestination());
		System.out.println("Duation: "+this.selectedPlan.getDuration()+" Days");
		System.out.println("____________________________________________________");
		System.out.println("Cost:\t\t"+computeAmount());
		System.out.println("Tax:\t\t"+computeTax());
		System.out.println("____________________________________________________");
		System.out.println("Total Amount: "+computeTotalAmount());
		System.out.println("____________________________________________________");		
	}
	public void setDate(Date date) {
		this.date = date;
	}

	public void setPaidAmount(double paidAmount) {
		this.paidAmount = paidAmount;
	}
	public void setSelectedPlan(Plan selectedPlan) {
		this.selectedPlan = selectedPlan;
	}
	@Override
	public String toString() {
		return "\nPlan Details:\nDate: "+date+"\n____________________________________________________"+"\nSource: "+selectedPlan.getSource()+
				"\nDestination: "+selectedPlan.getDestination()+"\nDuration: "+selectedPlan.getDuration()+"\n____________________________________________________"+
				"\nCost:\t\t"+computeAmount()+"\nTax:\t\t"+computeTax()+"\n____________________________________________________"+
				"\nTotal Amount: "+computeTotalAmount()+"\n____________________________________________________"; 
	}
}
