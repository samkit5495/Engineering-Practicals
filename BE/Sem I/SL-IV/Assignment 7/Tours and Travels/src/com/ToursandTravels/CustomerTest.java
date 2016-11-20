package com.ToursandTravels;

import static org.junit.Assert.*;

import org.junit.Test;

public class CustomerTest {

	@Test
	public void test() {
		Customer c=new Customer("Samkit", "Pune", "8600086024", 21, "Male");
		ToursandTravels.obj.newCustomer(c);
		boolean expected=true;
		boolean actual=ToursandTravels.obj.hasCustomer("Samkit");
		assertEquals(expected, actual);
		}
	}