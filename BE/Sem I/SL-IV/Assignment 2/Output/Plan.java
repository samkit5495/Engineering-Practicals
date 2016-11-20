package com.ToursandTravels;

import java.util.HashSet;

public class Plan {
	private int id;
	private String source;
	private String destination;
	private int duration;
	private double cost;
	private HashSet<Customer> planCustList=null;
	public Plan() {
		super();
		// TODO Auto-generated constructor stub
		this.planCustList=new HashSet<Customer>();
	}
	public Plan(int id, String source, String destination, int duration, double cost) {
		super();
		this.id = id;
		this.source = source;
		this.destination = destination;
		this.duration = duration;
		this.cost = cost;
		this.planCustList=new HashSet<Customer>();
	}
	public double getCost() {
		return cost;
	}

	public String getDestination() {
		return destination;
	}

	public int getDuration() {
		return duration;
	}

	public int getId() {
		return id;
	}

	public String getSource() {
		return source;
	}

	public void newUsingCustomer(Customer c)
	{
		planCustList.add(c);
	}

	public void setCost(double cost) {
		if(cost>=0)
			this.cost = cost;
		else
			System.out.println("Enter Valid Cost");
	}

	public void setDestination(String destination) {
		this.destination = destination;
	}

	public void setDuration(int duration) {
		this.duration = duration;
	}

	public void setId(int id) {
		this.id = id;
	}
	public void setSource(String source) {
		this.source = source;
	}
	@Override
	public String toString() {
		String s= "Plan [id=" + id + ", source=" + source + ", destination=" + destination + ", duration=" + duration
				+ ", cost=" + cost + "]";
		for(Customer c:planCustList)
			s+="\n"+c;
		return s;
	}
}
