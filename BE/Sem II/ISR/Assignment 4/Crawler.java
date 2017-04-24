import java.io.*;

public class Crawler 
{
	String baseLink;	
	public static void main(String a[])
	{
		Crawler crawler=new Crawler();
		System.out.println("Enter the Start String");
		InputStreamReader converter = new InputStreamReader(System.in);
	    BufferedReader in = new BufferedReader(converter);
		try
		{
			crawler.baseLink = in.readLine();
		}
		catch(Exception ex)
		{
					
		}
		System.out.println("Base Link: "+crawler.baseLink);
		crawler.crawl();
	}
	public void crawl()
	{
		String arr[]=new String[1500];
		String arr2[]=new String[1500];
		try{
			  FileInputStream fstream = new FileInputStream("unipune.html");
			  DataInputStream in = new DataInputStream(fstream);
			  BufferedReader br = new BufferedReader(new InputStreamReader(in));
			  String strLine;
			  int i=0;
			  while ((strLine = br.readLine()) != null) 
			  {
				  if(strLine.contains(baseLink))
				  {					  
					  arr[i]=strLine.substring(strLine.indexOf(baseLink));	
					  int index=arr[i].indexOf("\"");
					  if(index>0)
					  {
					  //System.out.println(index);
					  	arr2[i]=arr[i].substring(0,index);
					  	System.out.println(arr2[i]);
					  }
					  //System.out.println (strLine.substring(strLine.indexOf(baseLink)));
					  
					  i++;
				  }			  
			  }
			  in.close();
		   }
			catch (Exception e)
			{
					System.err.println("Error: " + e.getMessage());
			}		
	}
}
