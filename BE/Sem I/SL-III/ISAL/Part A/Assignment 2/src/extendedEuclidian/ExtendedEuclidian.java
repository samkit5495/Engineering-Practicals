package extendedEuclidian;

import java.util.Scanner;

public class ExtendedEuclidian 
{
	private int a,b,x,y,d,q,r,x1,x2,y1,y2,A,B;
	private Scanner sc=new Scanner(System.in);
	public ExtendedEuclidian()
	{
		System.out.println("Enter two Digits to find GCD ");
		this.a=sc.nextInt();
		this.b=sc.nextInt();
		sc.close();
		calGCD();
		System.out.println("x = "+x+" y = "+y+" d = "+d);
		System.out.println("That is, gcd("+A+","+B+") = "+d+" and "+x+" x "+A+" + "+y+" x "+B+" = "+d+".");
	}
	public ExtendedEuclidian(int a,int b)
	{
		sc.close();
		this.a=a;
		this.b=b;
		calGCD();
		System.out.println("x = "+x+" y = "+y+" d = "+d);
		System.out.println("That is, gcd("+A+","+B+") = "+d+" and "+x+" x "+A+" + "+y+" x "+B+" = "+d+"."); 
	}
	private void check()
	{
		if(a<b)
		{
			int t=this.a;
			this.a=this.b;
			this.b=t;
		}
	}
	private void calGCD()
	{
		this.A=this.a;
		this.B=this.b;
		check();
		if(b==0)
		{
			d=a;
			x=1;
			y=0;
			return;
		}
		x2=1;
		x1=0;
		y2=0;
		y1=1;
		System.out.println("q\tr\tx\ty\ta\tb\tx2\tx1\ty2\ty1\n");
		while(b>=0)
		{
			System.out.println(q+"\t"+r+"\t"+x+"\t"+y+"\t"+a+"\t"+b+"\t"+x2+"\t"+x1+"\t"+y2+"\t"+y1+"\n");
			try
			{
				q= (int) java.lang.Math.floor(a/b);
			}
			catch(Exception e){
				break;
			}
			r = a - (q*b);
			x = x2 - (q*x1);
			y = y2 - (q*y1);
			a= b;
			b = r;
			x2 = x1;
			x1 = x;
			y2 = y1;
			y1 = y; 
		}
		d=a;
		x=x2;
		y=y2;
	}
}
