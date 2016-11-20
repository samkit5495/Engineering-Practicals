/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package decode;

import java.util.*;
import org.json.simple.*;
import org.json.simple.parser.*;
//import java.util.Iterator;
//import java.util.Set;
//import org.json.simple.JSONArray;
//import org.json.simple.JSONObject;
//import org.json.simple.parser.JSONParser;
//import org.json.simple.parser.ParseException;
/**
 *
 * @author Samkit
 */

public class Decode 
{
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        // TODO code application logic here
        JSONParser parser=new JSONParser();
        //{"student":{"classname":"TE","name":"XYZ","marks":[{"DBMSP":"60","DBMSO":"60","DBMST":"60"},{"TOC":"50"},{"CNT":"65"}]}}
        //String jsonString="{\"student\":{\"classname\":\"TE\",\"name\":\"XYZ\",\"marks\":[{\"DBMS\":\"60\"},{\"TOC\":\"50\"},{\"CNT\":\"65\"}]}}";
        String jsonString="{\"student\":{\"classname\":\"TE\",\"name\":\"XYZ\",\"marks\":[{\"DBMSP\":\"60\",\"DBMSO\":\"60\",\"DBMST\":\"60\"},{\"TOC\":\"50\"},{\"CNT\":\"65\"}]}}";
        try{
                JSONObject mainobj = (JSONObject)parser.parse(jsonString);

                JSONObject student =(JSONObject)mainobj.get("student");

                System.out.println("Name - "+student.get("name"));
                System.out.println("Classname - "+student.get("classname"));

                JSONArray marks=(JSONArray)student.get("marks");
                for(int i=0;i<marks.size();i++)
                {
                        JSONObject subMark =(JSONObject)marks.get(i);

                        Set keys=subMark.keySet();
                        Iterator keysItr=keys.iterator();
                        while(keysItr.hasNext())
                        {
                                Object key=keysItr.next();
                                System.out.println(key+" - "+subMark.get(key));
                        }
                }


        }
        catch(ParseException pe){
                System.out.println(pe);
        }

    }
    
}
