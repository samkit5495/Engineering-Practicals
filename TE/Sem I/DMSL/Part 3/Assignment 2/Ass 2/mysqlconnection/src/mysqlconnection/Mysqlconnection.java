/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mysqlconnection;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
import java.sql.CallableStatement;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Types;
import java.io.*;


/**
 *
 * @author Samkit
 */
public class Mysqlconnection {

    /**
     * @param args the command line arguments
     */
       private CallableStatement clmt;
       public Connection getConnection()
       {
           Connection con=null;
           try
           {
               con=(Connection)DriverManager.getConnection("jdbc:mysql://localhost:3307/test","root","mysql");
           }
           catch(Exception e)
           {
                System.out.println("Error in Connection"+e);
           }
           return con;
       }
       
        public void getCustomer()
         {
             try{
                 Connection con=getConnection();
                 Statement st=(Statement) con.createStatement();
                 ResultSet res=st.executeQuery("select * from customer");
                 while(res.next())
                 {
                     System.out.print(res.getString(1)+"   ");
                     System.out.print(res.getString(2)+"   ");
                     System.out.print(res.getString(3)+"    ");
                     System.out.println(res.getString(4)+"   ");
                 }
                 res.close();
                 con.close();
             }
             catch(Exception e)
             {
                 System.out.println("Error in fetching data");

             }
         }
        public void callProcedure1()
        {
            try{
                Connection con=getConnection();
                clmt = con.prepareCall("{call proc1}");
                ResultSet res=clmt.executeQuery();
                if(res.next())
                {
                    System.out.println(res.getString(1));
                }
            }
                catch(Exception e)
                {
                    e.printStackTrace();
                }
        }
        public void callProcedure2()
        {
            try{
                Connection con=getConnection();
                clmt=con.prepareCall("{call proc2}");
                ResultSet res=clmt.executeQuery();
                while(res.next())
                {
                    System.out.println(res.getString(1)+ "\t" +res.getString(4));
                }
                
            }
            catch(Exception e)
                {
                    e.printStackTrace();
                }
        }
        public void callProcedure3(String code,String name)
        {
            try{
                Connection con=getConnection();
                clmt=con.prepareCall("{call proc3(?,?)}");
                clmt.setString(1,code);
                clmt.setString(2,name);
                int i=clmt.executeUpdate();
                if(i!=0)
                 System.out.println("Inserted Successfully");
                else
                    System.out.println("Not Inserted");
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }

    public static void main(String[] args) {
        // TODO code application logic here
        Mysqlconnection obj=new Mysqlconnection();
        obj.getCustomer();
        obj.callProcedure1();
        obj.callProcedure2();
        obj.callProcedure3("1234","samkit");
     
    }
    
}
