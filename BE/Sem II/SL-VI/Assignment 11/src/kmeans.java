import java.util.ArrayList;
import java.util.Scanner;

public class kmeans {

	int n;
	int p;
	int d[];
	ArrayList<ArrayList<Integer>> k;
	ArrayList<ArrayList<Integer>> tempk;
	int m[];
	int diff[];
	public kmeans(int n,int p) {
		// TODO Auto-generated constructor stub
		this.n=n;
		this.d=new int[n];
		this.p=p;
		k=new ArrayList<>();
		tempk=new ArrayList<>();
		for(int i=0;i<p;i++)
		{
			k.add(new ArrayList<>());
			tempk.add(new ArrayList<>());
		}
		m=new int[p];
		diff=new int[p];		
	}
	
	public int cal_diff(int a)
	{
		for(int i=0;i<p;i++)
		{
			if(a>m[i])
				diff[i]=a-m[i];
			else
				diff[i]=m[i]-a;
		}
		int temp=diff[0],in=0;
		for(int i=0;i<p;i++)
		{
			if(temp>diff[i])
			{
				temp=diff[i];
				in=i;
			}
		}
		return in;
	}
	public void cal_mean()
	{
		for(int i=0;i<p;i++)
		{
			int sum=0;
			for(int j:k.get(i))
			{
				sum+=j;
			}
			try{
				m[i]=sum/k.get(i).size();
			}
			catch(ArithmeticException e){
				m[i]=0;
			}
			
		}
	}
	public boolean check()
	{
		if(k.equals(tempk))
			return true;
		return false;
	}
	@SuppressWarnings("unchecked")
	public void start()
	{
		for(int i=0;i<p;i++)
			m[i]=d[i];
		boolean f;
		do{
			for(int i=0;i<n;i++)
			{
				int temp=cal_diff(d[i]);
				k.get(temp).add(d[i]);
			}
			System.out.println("K:");
			System.out.println(k);
			cal_mean();
			f=check();
			for(int i=0;i<p;i++)
			{
				System.out.println("Custer: "+i+" Elements: "+k.get(i));
			}
			for(int i=0;i<p;i++)
			{
				tempk.set(i, (ArrayList<Integer>) k.get(i).clone());
				k.get(i).clear();
			}
		}while(!f);
	}
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter N: ");
		int n=sc.nextInt();
		System.out.println("Enter P clusters size: ");
		int p=sc.nextInt();
		kmeans k=new kmeans(n, p);
		System.out.println("Enter N elements: ");
		for(int i=0;i<n;i++)
			k.d[i]=sc.nextInt();
		k.start();
		sc.close();
	}
}
