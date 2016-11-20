package Watch;
import java.util.Date;


public class Time {
	private int hr;
	private int min;
	public Time() {
		super();
		// TODO Auto-generated constructor stu
		//set current hours and minutes in hr and min variables
		Date d=new Date();
		this.hr=d.getHours();
		this.min=d.getMinutes();
	}

	//set given hr and min values in hr and min variables
	public Time(int hr, int min) {
		super();
		if(hr>=1 && hr<=12 && min>=1 && min<=60)
		{
			this.hr = hr;
			this.min = min;
		}
		else
		{
			this.hr=1;
			this.min=1;
			System.out.println("Invalid Time");
		}
	}
	
	//increment hours
	public void advanceHr()
	{
		this.hr=hr%12+1;
	}

	//increment minutes
	public void advanceMin()
	{
		this.min=min%60+1;
	}
	
	//getter and setter of hr and min with validation
	public String getHr() {
		if(hr<=9)
			return "0"+hr;
		else
			return  ""+hr;
	}
	public String getMin() {
		if(min<=9)
			return "0"+min;
		else
			return  ""+min;
	}
	public void setHr(int hr) {
		if(hr>=1&&hr<=12)
			this.hr = hr;
		else
			System.out.println("Invalid Hr Value");
	}
	public void setMin(int min) {
		if(min>=1&&min<=60)
			this.min = min;
		else
			System.out.println("Invalid Min Value");
	}
	public String toString() {
		return "Hr:Min\n" + getHr() +":"+ getMin()+"\n";
	}
}
