import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

public class JsonEncodeDemo
{

   public static void main(String[] args)
   {
	   JSONObject student=new JSONObject();
	   student.put("name","XYZ");
	   student.put("classname","TE");

	   JSONArray marksarray = new JSONArray();

	   JSONObject DBMS=new JSONObject();
	   DBMS.put("DBMSO","60");
	   DBMS.put("DBMST","60");
	   marksarray.add(DBMS);

	   JSONObject TOC=new JSONObject();
	   TOC.put("TOCO","50");
	   TOC.put("TOCT","50");
	   marksarray.add(TOC);

	   JSONObject CNT=new JSONObject();
	   CNT.put("CNTO","65");
	   CNT.put("CNTL","65");
	   marksarray.add(CNT);

	   student.put("marks",marksarray);

	   JSONObject obj = new JSONObject();
	   obj.put("student",student);
	   System.out.print(obj);

   }
}