package com.ToursandTravels;

import java.util.Scanner;

public class Program {

	private static Scanner sc=new Scanner(System.in);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		while(true)
		{
			System.out.println(ToursandTravels.obj.getName());
			switch(mainMenu())
			{
			case 1:
				newCustomer();
				break;
			case 2:
				System.out.println("Enter Name");
				Customer c=ToursandTravels.obj.findCustomer(sc.next());
				if(c==null)
					System.out.println("Customer Not Found!!!");
				else
					System.out.println(c);
				break;
			case 3:
				newVehicle();
				break;
			case 4:
				newPlan();
				break;
			case 5:
				return;
			default:
				System.out.println("Invalid Selection!!!");
				break;
			}
		}
	}
	private static int mainMenu()
	{
		System.out.println("1. New Customer");
		System.out.println("2. Select Customer");
		System.out.println("3. New Vehicle");
		System.out.println("4. New Plan");
		System.out.println("5. Exit");
		return sc.nextInt();
	}
	private static void newCustomer()
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
			return;
		}
		System.out.println(c);
		ToursandTravels.obj.newCustomer(c);
	}
	private static void newPlan()
	{
		Plan p=new Plan();
		System.out.println("Enter Source");
		p.setSource(sc.next());
		System.out.println("Enter Destination");
		p.setDestination(sc.next());
		System.out.println("Enter Cost");
		p.setCost(sc.nextDouble());
		System.out.println(p);
		ToursandTravels.obj.newPlan(p);
	}
	
	private static void newVehicle()
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
		System.out.println(v);
		ToursandTravels.obj.newVehicle(v);
	}

}
