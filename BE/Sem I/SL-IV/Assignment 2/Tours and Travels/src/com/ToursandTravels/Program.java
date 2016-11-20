package com.ToursandTravels;

import java.util.Date;
import java.util.Scanner;

public class Program {

	private static Scanner sc=new Scanner(System.in);
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(ToursandTravels.obj.getName());
		int ch,ch1;
		Customer c=null;
		while((ch=mainMenu())!=0)
		{
			switch(ch)
			{
			case 1:
				c=newCustomer();
			case 2:
				if(ch==2)
				{
					if(ToursandTravels.obj.getCustList().size()==0)
					{
						System.out.println("No Customers Added");
						break;
					}
					else
						ToursandTravels.obj.viewCustomers();
					System.out.println("Enter Customer Name");
					c=ToursandTravels.obj.findCustomer(sc.next());
				}
				if(c==null)
				{
					System.out.println("Customer Not Found!!!");
					break;
				}
				System.out.println(c);
				while((ch1=suMenu1())!=0)
				{
					switch(ch1)
					{
					case 1:
						if(ToursandTravels.obj.getPlanList().size()==0)
						{
							System.out.println("No Plans Added");
							break;
						}
						else
							ToursandTravels.obj.viewPlans();
						System.out.println("Select Plan");
						Plan p=ToursandTravels.obj.getPlanList().get(sc.nextInt());
						if(p==null)
						{
							System.out.println("Plan Not Found!!!");
							break;
						}
						Bill b=c.newBill(p);
						b.print(c);
						System.out.println("Enter Paid Amount: ");
						b.setPaidAmount(sc.nextDouble());
						break;
					case 2:
						if(c.getBillList().size()==0)
							System.out.println("No Bookings");
						else
							c.viewBills();
						break;
					default:
						System.out.println("Invalid Selection!!!");
						break;
					}
				}
				break;
			case 3:
				newVehicle();
				break;
			case 4:
				if(ToursandTravels.obj.getVehList().size()==0)
					System.out.println("No Vehicles Added");
				else
					ToursandTravels.obj.viewVehicles();
				break;
			case 5:
				newPlan();
				break;
			case 6:
				if(ToursandTravels.obj.getPlanList().size()==0)
					System.out.println("No Plans Added");
				else
					ToursandTravels.obj.viewPlans();
				break;
			case 7:
				newStaff();
				break;
			case 8:
				if(ToursandTravels.obj.getStaffList().size()==0)
				{
					System.out.println("No Staff Added");
					break;
				}
				else
					ToursandTravels.obj.viewStaff();
				System.out.println("Enter Staff Name");
				Staff s=ToursandTravels.obj.findStaff(sc.next());
				if(s==null)
				{
					System.out.println("Staff Not Found!!!");
					break;
				}
				while((ch1=subMenu(s))!=0)
				{
					switch(ch1)
					{
					case 1:
						System.out.println("Enter Attendence out of 31");
						int attendence=sc.nextInt();
						if(attendence>=0&&attendence<=31)
							System.out.println(s.calculateSalary(attendence));
						else
							System.out.println("Invalid Attendence!!!");
						break;
					case 2:
						if(s instanceof WorkingStaff)
						{
							System.out.println("Enter New Designation");
							((WorkingStaff)s).setDesignation(sc.next());
						}
						else
						{
							System.out.println("License List");
							((DriverStaff)s).showLicenses();
						}
						break;
					case 3:
						if(s instanceof DriverStaff)
						{
							System.out.println("Enter License No");
							((DriverStaff)s).newLicense(sc.next());
							break;
						}
					default:
						System.out.println("Invalid Selection");
						break;
					}
				}
				break;
			case 9:
				System.out.println("Todays Business: "+ToursandTravels.obj.computeCash(new Date()));
				break;
			default:
				System.out.println("Invalid Selection!!!");
				break;
			}
		}
	}
	
	private static int mainMenu()
	{
		System.out.println("0. Exit");
		System.out.println("1. New Customer");
		System.out.println("2. Select Customer");
		System.out.println("3. New Vehicle");
		System.out.println("4. Show Vehicle");
		System.out.println("5. New Plan");
		System.out.println("6. Show Plan");
		System.out.println("7. New Staff");
		System.out.println("8. Select Staff");
		System.out.println("9. Todays Business");
		return sc.nextInt();
	}
	
	private static Customer newCustomer()
	{
		Customer c=new Customer();
		System.out.println("Enter Name");
		c.setName(sc.next());
		System.out.println("Enter Address");
		c.setAddress(sc.next());
		System.out.println("Enter Mobile No");
		c.setMobileNo(sc.next());
		System.out.println("Enter Age");
		c.setAge(sc.nextInt());
		System.out.println("Select Gender\n1. Male\n2. Female");
		switch(sc.nextInt())
		{
		case 1:
			c.setGender("Male");
			break;
		case 2:
			c.setGender("Female");
			break;
		default:
			System.out.println("Invalid Selection");
			return null;
		}
		ToursandTravels.obj.newCustomer(c);
		return c;
	}
	private static Plan newPlan()
	{
		Plan p=new Plan();
		System.out.println("Enter ID");
		p.setId(sc.nextInt());
		System.out.println("Enter Source");
		p.setSource(sc.next());
		System.out.println("Enter Destination");
		p.setDestination(sc.next());
		System.out.println("Enter Duration");
		p.setDuration(sc.nextInt());
		System.out.println("Enter Cost");
		p.setCost(sc.nextDouble());
		ToursandTravels.obj.newPlan(p);
		return p;
	}
	
	private static Staff newStaff()
	{
		Staff s=null;
		System.out.println("1. Driving Staff");
		System.out.println("2. Working Staff");
		if(sc.nextInt()==1)
			s=new DriverStaff();
		else
		{
			s=new WorkingStaff();
			System.out.println("Designation");
			((WorkingStaff)s).setDesignation(sc.next());
		}
		System.out.println("Enter Staff Name");
		s.setName(sc.next());
		System.out.println("Enter Salary");
		s.setSalary(sc.nextDouble());
		System.out.println("Enter Mobile No");
		s.setMobileNo(sc.next());
		System.out.println("Enter Age");
		s.setAge(sc.nextInt());
		System.out.println("Select Gender\n1. Male\n2. Female");
		switch(sc.nextInt())
		{
		case 1:
			s.setGender("Male");
			break;
		case 2:
			s.setGender("Female");
			break;
		default:
			System.out.println("Invalid Selection");
			return null;
		}
		ToursandTravels.obj.newStaff(s);
		return s;
	}
	
	private static Vehicle newVehicle()
	{
		Vehicle v=new Vehicle();
		System.out.println("Enter Vehicle No");
		v.setVehicleNumber(sc.next());
		System.out.println("Enter Vehicle Model");
		v.setVehicleModel(sc.next());
		System.out.println("Enter Vehicle Type");
		v.setVehicleType(sc.next());
		System.out.println("Enter Capacity");
		v.setVehicleCapacity(sc.nextInt());
		ToursandTravels.obj.newVehicle(v);
		return v;
	}
	
	private static int subMenu(Staff s)
	{
		System.out.println("0. Back");
		System.out.println("1. Calculate Salary");
		if(s instanceof WorkingStaff)
		{
			System.out.println("2. Change Designation");
		}
		if(s instanceof DriverStaff)
		{
			System.out.println("2. Show License");
			System.out.println("3. Add License");
		}
		return sc.nextInt();
	}
	
	private static int suMenu1()
	{
		System.out.println("0. Back");
		System.out.println("1. New Booking");
		System.out.println("2. Previous Bookings");
		return sc.nextInt();
	}
}
