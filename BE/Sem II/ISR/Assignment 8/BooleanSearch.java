/*
Name: Jain Samkitkumar Hasmukhlal 
Roll no:20 BEIT
Title: Boolean Searching
*/

import java.io.*;
import java.util.*;

class BooleanSearch
{
    public static void main(String args[]) throws IOException
    {
        System.out.println("\n\nAllowed-AND/OR?ANDNOT");
        System.out.println("\n Enter teh search string:");
        String query=new String();
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        query=br.readLine();
        StringTokenizer st=new StringTokenizer(query," ");
        String[]keyword=new String[st.countTokens()];
        String[]Operators=new String[10];
        for(int j=0;j<st.countTokens();j++)
            keyword[j]=" ";
        int keywordcount=0,opcount=0;
        while(st.hasMoreElements())
        {
            String temp=st.nextToken();
            if(temp.equals("AND")||temp.equals("OR")||temp.equals("ANDNOT"))
            {
                Operators[opcount++]=temp;
                keywordcount++;
            }
            else
            {
                temp=temp.toLowerCase();
                if(keyword[keywordcount].length()==1)
                    keyword[keywordcount]=temp;
                else
                {
                    keyword[keywordcount]=keyword[keywordcount].concat(" ");
                    keyword[keywordcount]=keyword[keywordcount].concat(temp);
                }
            }
        }
        String[]Foundln=new String[3];
        int foundcount=0;
        for(int i=1;i<=3;i++)
        {
            boolean intermittent =false;
            FileInputStream inStream= new FileInputStream("doc"+i+".txt");
            int inBytes =inStream.available();
            byte inBuf[]=new byte[inBytes];
            int bytesRead= inStream.read(inBuf,0,inBytes);
            String docs=new String(inBuf);
            docs=docs.toLowerCase();
            inStream.close();
            if(opcount>0)
            {
                for(int j=0;j<opcount;j++)
                {
                    if(Operators[j].equals("AND"))
                    {
                        if(j==0)
                        {
                            if((docs.indexOf(keyword[j])!=-1) && (docs.indexOf(keyword[j+1])!=-1))
                                intermittent=true;
                            else
                                intermittent=false;
                            continue;
                        }
                        else
                        {
                            if(docs.indexOf(keyword[j+1])!=-1)
                                intermittent=intermittent && true;
                            else
                                intermittent=intermittent && false;
                        }
                    }
                    else if(Operators[j].equals("OR"))
                    {
                        if(j==0)
                        {
                            if((docs.indexOf(keyword[j])!=-1) || (docs.indexOf(keyword[j+1])!=-1))
                                intermittent=true;
                            else
                                intermittent=false;
                            continue;
                        }
                        else
                        {
                            if(docs.indexOf(keyword[j+1])!=-1 )
                                intermittent=intermittent|| true;
                            else
                                intermittent=intermittent|| false;
                        }
                    }
                    else if(Operators[j].equals("ANDNOT"))
                    {
                        if(j==0)
                        {
                            if((docs.indexOf(keyword[j])!=-1) && (docs.indexOf(keyword[j+1])==-1))
                                intermittent=true;
                            else
                                intermittent=false;
                            continue;
                        }
                        else
                        {
                            if(docs.indexOf(keyword[j+1])==-1)
                                intermittent=intermittent && true;
                            else
                                intermittent=intermittent && false;
                        }
                    }
                }
                if(intermittent)
                    Foundln[foundcount++]="doc"+i+".txt";
            }
            else
            {
                if(docs.indexOf(keyword[0])!=-1)
                    Foundln[foundcount++]="doc"+i+".txt";
            }
        }
        if(foundcount==0)
            System.out.println("NotFound in Any Document");
        else
        {
             for(int j=0;j<foundcount;j++)
                System.out.println(Foundln[j]);
        }
    }
}
