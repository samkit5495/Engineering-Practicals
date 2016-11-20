public class PaytmStrategy implements PaymentStrategy {

private String mailid;
private String pwd;

public PaytmStrategy(String email, String pwd){

this.mailid=email;

this.pwd=pwd;

}

public void pay(int amount) {

System.out.println("******\nAmount is "+amount +"\nPayment done using Paytm");

}

}
