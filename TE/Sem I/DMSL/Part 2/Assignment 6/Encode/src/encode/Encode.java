/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package encode;
import org.json.simple.*;
/**
 *
 * @author Samkit
 */
public class Encode {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        // TODO code application logic here
        JSONObject student=new JSONObject();
        student.put("name","XYZ");
        student.put("classname","TE");

        JSONArray marksarray = new JSONArray();

        JSONObject DBMS=new JSONObject();
        DBMS.put("DBMS","60");
        marksarray.add(DBMS);

        JSONObject TOC=new JSONObject();
        TOC.put("TOC","50");
        marksarray.add(TOC);

        JSONObject CNT=new JSONObject();
        CNT.put("CNT","65");
        marksarray.add(CNT);

        student.put("marks",marksarray);

        JSONObject obj = new JSONObject();
        obj.put("student",student);
        System.out.print(obj);
    }
    
}
