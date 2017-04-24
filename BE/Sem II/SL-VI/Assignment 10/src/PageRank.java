import java.util.Scanner;

public class PageRank {

	int n;
	float pagerank[];
	int[][] mat;
	public PageRank(int n) {
		// TODO Auto-generated constructor stub
		this.n=n;
		pagerank=new float[n];
		mat=new int[n][n];
	}
	
	public void cal()
	{
		float init=1/(float)n;
		System.out.println("Pagerank at Step 0");
		for(int i=0;i<n;i++)
		{
			pagerank[i]=init;
			System.out.println((i+1)+" "+pagerank[i]);
		}
		int u=1;
		while(u<=2)
		{
			float temp[]=new float[n];
			for(int i=0;i<n;i++)
			{
				temp[i]=pagerank[i];
				pagerank[i]=0;
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(mat[j][i]==1)
					{
						int c=0;
						for(int k=0;k<n;k++)
							if(mat[j][k]==1)
								c++;
						pagerank[i]+=temp[j]/c;
					}
				}
			}
			System.out.println("Pagerank at Step "+u);
			for(int i=0;i<n;i++)
				System.out.println((i+1)+" "+pagerank[i]);
			u++;
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter n:");
		PageRank p=new PageRank(sc.nextInt());
		System.out.println("Enter adjacet matrix");
		for(int i=0;i<p.n;i++)
		{
			for(int j=0;j<p.n;j++)
			{
				p.mat[i][j]=sc.nextInt();
			}
		}
		p.cal();
	}

}
