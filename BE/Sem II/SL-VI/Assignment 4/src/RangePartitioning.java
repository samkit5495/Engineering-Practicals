
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;


public class RangePartitioning {

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		
		Class.forName("com.mysql.jdbc.Driver");
		
		Connection conn=DriverManager.getConnection("jdbc:mysql://localhost/sam", "root","1234");
		while(true)
		{
			System.out.println("Enter choice:\n1. April\n2. May\n");
			Scanner sc=new Scanner(System.in);
			Statement st;
			ResultSet rs;
			switch(sc.nextInt())
			{
				case 1:
					st=conn.createStatement();
					rs= st.executeQuery("select * from cust_apr");
					if(rs.next())
					{
						System.out.println("ID: "+rs.getInt(1));
						System.out.println("name: "+rs.getString(2));
						System.out.println("dob: "+rs.getDate(3));
					}
					break;
				case 2:
					st=conn.createStatement();
					rs= st.executeQuery("select * from cust_may");
					if(rs.next())
					{
						System.out.println("ID: "+rs.getInt(1));
						System.out.println("name: "+rs.getString(2));
						System.out.println("dob: "+rs.getDate(3));
					}
					break;
			}
			
		}
	}
	
}
