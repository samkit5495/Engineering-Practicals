package com.ToursandTravels;

public class ToursandTravels 
{
	public static ToursandTravels obj=new ToursandTravels();
	private Customer c=null;
	private Vehicle v=null;
	private Plan p=null;
	private Staff s=null;
	private final String name="Samkit Tours And Travels";
	private ToursandTravels()
	{
		
	}
	
	public Customer findCustomer(String name)
	{
		if(c.getName().equals(name))
			return c;
		else
			return null;
	}

	public String getName() {
		return name;
	}
	public void newCustomer(Customer c)
	{
		this.c=c;
	}
	public void newPlan(Plan p)
	{
		this.p=p;
	}
	public void newStaff(Staff s)
	{
		this.s=s;
	}
	public void newVehicle(Vehicle v)
	{
		this.v=v;
	}
	public void viewCustomers()
	{
		System.out.println(c);
	}
	public void viewPlans()
	{
		System.out.println(p);
	}
	public void viewStaff()
	{
		System.out.println(s);
	}
	public void viewVehicles()
	{
		System.out.println(v);
	}
	
}
