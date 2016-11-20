package com.ToursandTravels;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;

public class ToursandTravels 
{
	public static ToursandTravels obj=new ToursandTravels();
	private HashSet<Customer> custList=null;
	private HashMap<String,Vehicle> vehList=null;
	private HashMap<Integer,Plan> planList=null;
	private HashSet<Staff> staffList=null;
	private final String name="Samkit Tours And Travels";
	private ToursandTravels()
	{
		custList=new HashSet<>();
		vehList=new HashMap<>();
		planList=new HashMap<>();
		staffList=new HashSet<>();
	}
	
	public double computeCash(Date d)
	{
		double t=0;
		for(Customer c:custList)
			for(Bill b:c.getBillList())
				if(new SimpleDateFormat("dd/MM/yyyy").format(d).equals(new SimpleDateFormat("dd/MM/yyyy").format(b.getDate())))
					t+=b.getPaidAmount();
		return t;
	}

	public Customer findCustomer(String name)
	{
		for(Customer c : custList)
			if(c.getName().equals(name))
				return c;
		return null;
	}
	public Staff findStaff(String name)
	{
		for(Staff s:staffList)
			if(s.getName().equals(name))
				return s;
		return null;
	}
	public boolean hasCustomer(String name)
	{
		for(Customer c:custList)
		{
			if(c.getName().equals(name))
			 return true;
		}
		return false;
	}
	public HashSet<Customer> getCustList() {
		return custList;
	}
	public String getName() {
		return name;
	}
	public HashMap<Integer, Plan> getPlanList() {
		return planList;
	}
	public HashSet<Staff> getStaffList() {
		return staffList;
	}
	public HashMap<String, Vehicle> getVehList() {
		return vehList;
	}
	public void newCustomer(Customer c)
	{
		this.custList.add(c);
	}
	public void newPlan(Plan p)
	{
		this.planList.put(p.getId(),p);
	}

	public void newStaff(Staff s)
	{
		this.staffList.add(s);
	}

	public void newVehicle(Vehicle v)
	{
		this.vehList.put(v.getVehicleNumber(), v);
	}

	public void viewCustomers()
	{
		for(Customer c : custList)
			System.out.println(c);
	}

	public void viewPlans()
	{
		for(int i : planList.keySet())
			System.out.println(planList.get(i));
	}
	public void viewStaff()
	{
		for(Staff s : staffList)
		System.out.println(s);
	}
	public void viewVehicles()
	{
		for(String s : vehList.keySet())
		System.out.println(vehList.get(s));
	}
}
