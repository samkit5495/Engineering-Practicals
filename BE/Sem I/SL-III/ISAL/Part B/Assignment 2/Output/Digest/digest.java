import java.security.*;
import java.io.*;

class digest
{
   public static void main(String[] args)
   {
      try
      {
        //
	MessageDigest classMD = MessageDigest.getInstance("SHA1");

	//
	File inputTextFile = new File("data.txt");
	FileInputStream cfis = new FileInputStream(inputTextFile);
	BufferedInputStream cbis = new BufferedInputStream(cfis);
	byte[] cbuff = new byte[1024];

	while(cbis.available() != 0)
	{
	    int len = cbis.read(cbuff);
	    classMD.update(cbuff, 0, len);
	 }

	 cbis.close();
	 cfis.close();

	 byte[] classdigest = classMD.digest();

	 File outputTextFile = new File("digestoutput.txt");
	 FileOutputStream cfos = new FileOutputStream(outputTextFile);
	 BufferedOutputStream cbos = new BufferedOutputStream(cfos);
	 cbos.write(classdigest);
	 cbos.close();
	 cfos.close();

	}
	catch(Exception e)
	{
	   System.out.println("There was an exception. The exception was " + e.toString());
	}
   }
}

		
