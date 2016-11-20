package rsa;

import java.math.BigInteger;
import java.util.Random;

public class RSA 
{
	private BigInteger n,e,d,t,p,q;
	private Random r;
	private final static int bitLength=25;
 	RSA()
 	{
 		r=new Random();
 		p=BigInteger.probablePrime(bitLength, r);
 		q=BigInteger.probablePrime(bitLength, r);
 		cal();
 	}
 	
 	RSA(int p,int q)
 	{
 		r=new Random();
 		this.p=new BigInteger(p+"");
 		this.q=new BigInteger(q+"");
 		cal();
 	}
 	
 	private void cal()
 	{
 		n=p.multiply(q);
 		t=p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
 		e = BigInteger.probablePrime(bitLength / 2, r);
 		while (t.gcd(e).compareTo(BigInteger.ONE) > 0 && e.compareTo(t) < 0)
        {
            e.add(BigInteger.ONE);
        }
 		d = e.modInverse(t);
		System.out.println("p="+p);
		System.out.println("q="+q);
		System.out.println("n="+n);
		System.out.println("e="+e);
		System.out.println("d="+d);
 	}

 	public String encrypt(String plainText)
 	{
 		return new BigInteger(plainText.getBytes()).modPow(e, n).toString();
 	}
 	
 	public String decrypt(String cypherText)
 	{
 		return new String(new BigInteger(cypherText).modPow(d, n).toByteArray());
 	}
}
