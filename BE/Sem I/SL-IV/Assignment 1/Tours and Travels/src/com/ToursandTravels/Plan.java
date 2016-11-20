package com.ToursandTravels;

public class Plan {
	private String source;

	private String destination;
	private double cost;
	public double getCost() {
		return cost;
	}

	public String getDestination() {
		return destination;
	}

	public String getSource() {
		return source;
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

	public void setSource(String source) {
		this.source = source;
	}

	@Override
	public String toString() {
		return "Plan [source=" + source + ", destination=" + destination + ", cost=" + cost + "]";
	}
}
