import java.lang.*;
import java.io.*;
import java.util.*;

class Confletion
{

String high_frq_words[] =  {"i","am","cannot","into","our","thus" ,"about","is","to" ,"above", "you",
"too","after","a","is" ,"are","was","were","have","has","had","of","there","now","whom","next", "but",
"next","than","still","he","she","it","they","them","their","no","as","be","the","his","her","if"," in" ,"this"};

String str_token="",str_token_cmp="";
int i=0,flg=0,cnt=0,j=0,spe_cnt=0;;
BufferedReader br=null,br2=null;
FileWriter fw=null;


//----------------------------------Step One : removing high frequency words-------------------------------
void confletionStepOne(String filename) throws Exception
{
	br=new BufferedReader(new FileReader(filename) );
	fw = new FileWriter("Step1.txt");
	while((str_token = br.readLine()) != null  )
	{
		StringTokenizer st =new StringTokenizer(str_token," ,.");
		while(st.hasMoreTokens())
		{
			String str_tmp = st.nextToken();
			i=0;
			while(i<high_frq_words.length)
			{
				if(str_tmp.equals(high_frq_words[i++]))
				{
					flg=1;
					break;
				}
				else
					flg=0;
			}
			if(flg==0)
			{
//				System.out.println(str_tmp);
				fw.write(str_tmp + " ");
			}
		}
	}
	fw.close();
}
//--------------------------------------------------Step One Finished-----------------------------------------------


//----------------------------------------------Step Two : Suffix stripping-----------------------------------------
void confletionStepTwo(String filename) throws Exception
{
	br=new BufferedReader(new FileReader(filename) );
	fw = new FileWriter("Step2.txt");

	while((str_token = br.readLine()) != null  )
	{
		StringTokenizer st =new StringTokenizer(str_token," ");
		while(st.hasMoreTokens())
		{
			String str_tmp = st.nextToken();
			
			if (str_tmp.endsWith("ate"))
				str_tmp=	str_tmp.replace("ate","");

			if (str_tmp.endsWith("iveness"))
				str_tmp=str_tmp.replace("iveness","ive");

			if (str_tmp.endsWith("fulness"))
				str_tmp=	str_tmp.replace("fulness","ful");

			if (str_tmp.endsWith("ed"))
				str_tmp=	str_tmp.replace("ed","");

			if (str_tmp.endsWith("ousness"))
				str_tmp=	str_tmp.replace("ousness","ous");

			if (str_tmp.endsWith("sses"))
				str_tmp=	str_tmp.replace("sses","ss");

			if (str_tmp.endsWith("ness"))
				str_tmp=	str_tmp.replace("ness","");

			if (str_tmp.endsWith("ies"))
				str_tmp=	str_tmp.replace("ies","y");

			if (str_tmp.endsWith("s"))
				str_tmp=	str_tmp.replace("s","");

			if (str_tmp.endsWith("eed"))
				str_tmp=	str_tmp.replace("eed","ee");

			if (str_tmp.endsWith("ational"))
				str_tmp=	str_tmp.replace("ational","ate");

			if (str_tmp.endsWith("tional"))
				str_tmp=	str_tmp.replace("tional","tion");

			if (str_tmp.endsWith("ization"))
				str_tmp=	str_tmp.replace("ization","ize");

			if (str_tmp.endsWith("ation"))
				str_tmp=	str_tmp.replace("ation","ate");

			if (str_tmp.endsWith("ator"))
				str_tmp=	str_tmp.replace("ator","ate");

			if (str_tmp.endsWith("iviti"))
				str_tmp=	str_tmp.replace("iviti","ive");

			if (str_tmp.endsWith("biliti"))
				str_tmp=	str_tmp.replace("biliti","ble");

			if (str_tmp.endsWith("icate"))
				str_tmp=	str_tmp.replace("icate","ic");

			if (str_tmp.endsWith("alize"))
				str_tmp=	str_tmp.replace("alize","al");

			if (str_tmp.endsWith("iciti"))
				str_tmp=	str_tmp.replace("iciti","ic");

			if (str_tmp.endsWith("ical"))
				str_tmp=	str_tmp.replace("ical","ic");

			if (str_tmp.endsWith("ative"))
				str_tmp=	str_tmp.replace("ative","");

			if (str_tmp.endsWith("ful"))
				str_tmp=	str_tmp.replace("ful","");
		
			if (str_tmp.endsWith("ism"))
				str_tmp=	str_tmp.replace("ism","");

			if (str_tmp.endsWith("ous"))
				str_tmp=	str_tmp.replace("ous","");

			if (str_tmp.endsWith("ive"))
				str_tmp=	str_tmp.replace("ive","");

			if (str_tmp.endsWith("ize"))
				str_tmp=	str_tmp.replace("ize","");

			if (str_tmp.endsWith("ship"))
				str_tmp=	str_tmp.replace("ship","");

			if (str_tmp.endsWith("al"))
				str_tmp=	str_tmp.replace("al","");

			if (str_tmp.endsWith("ance"))
				str_tmp=	str_tmp.replace("ance","");

			if (str_tmp.endsWith("ence"))
				str_tmp=	str_tmp.replace("ence","");

			if (str_tmp.endsWith("able"))
				str_tmp=	str_tmp.replace("able","");

			if (str_tmp.endsWith("ant"))
				str_tmp=	str_tmp.replace("ant","");

			if (str_tmp.endsWith("ment"))
				str_tmp=	str_tmp.replace("ment","");
			
//			System.out.println(str_tmp);
			fw.write(str_tmp + " ");
		}
	}
	fw.close();
}
//---------------------------------------------------Step Two Finished----------------------------------------------

//----------------------------------------------Step Three : ----------------------------------------
void confletionStepThree(String filename) throws Exception
{

	String str_one="",str_two="";
	br=new BufferedReader(new FileReader(filename) );
	ArrayList al=new ArrayList();

	fw = new FileWriter("Step3.txt");

	while((str_token = br.readLine()) != null   )
	{
		StringTokenizer st1 =new StringTokenizer(str_token," ");
		while(st1.hasMoreTokens())
		{
			al.add(st1.nextToken());
		}
	}

	Object o[]=al.toArray();
	Object o1[]=new Object[o.length];


	//-------Removing duplicate element
	for(i=0;i<o.length;i++)
	{
	       for(j=0;j<cnt;j++)
		          if(o[i].equals(o1[j]))
			             break;
	       if(j==cnt)
	       {
		          o1[cnt] = o[i];
		          cnt++;
	       }
	}
	//-----------------------------------------------

	System.out.println("----------------------------------------");
	System.out.println("Frequency \t Word");
	System.out.println("----------------------------------------");
	fw.write("----------------------------------------\n");
	fw.write("\nFrequency \t Word \n");
	fw.write("\n---------------------------------------- \n");
	for(i=0;i<cnt;i++)
	{
	       spe_cnt=0;
	       for(j=0;j<o.length;j++)
				if(o1[i].equals(o[j]))
					spe_cnt++;
	       System.out.println(spe_cnt+"\t\t"+o1[i]);
  	       fw.write("\n"+spe_cnt +"\t\t"+o1[i]+"\n");
	}
	fw.close();
}
//---------------------------------------------------Step Three Finished----------------------------------------------
}

public class ConfTest
{
	public static void main(String args[]) throws Exception
	{	
		Confletion cf=new Confletion();
		cf.confletionStepOne("input.txt");
		cf.confletionStepTwo("step1.txt");
		cf.confletionStepThree("step2.txt");
	}
}