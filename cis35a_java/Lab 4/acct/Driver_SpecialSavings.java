package acct;
/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 4- Exercise 1 Pt. 2
 * Date Due: 07/23/2018
 * Date Submitted: 07/23/2018
 * 
 *Detail: Inheritance from SavingsAccount Class
 *
 */
public class Driver_SpecialSavings {
	
	public static void main (String[] args)
	{
		SpecialSavings saver1  = new SpecialSavings(15000);
		SpecialSavings saver2  = new SpecialSavings(3000);
		
		System.out.printf("---%s---\n", "Saver 1");

		System.out.printf("%s\n","Acct > 10k");
		saver1.calculateMonthlyInterest();
		saver1.print();
		
		saver1.withdraw(9000);
		System.out.printf("%s\n","Acct Now < 10k (After Withdrawal)");
		saver1.calculateMonthlyInterest();
		saver1.print();
		
		System.out.printf("%s\n","Acct Now < 10k (After Deposit)");
		saver1.deposit(500);
		saver1.calculateMonthlyInterest();
		saver1.print();


		System.out.printf("---%s---\n", "Saver 2");
		System.out.printf("%s\n","Acct < 10k");
		saver2.calculateMonthlyInterest();
		saver2.print();
		
		saver2.deposit(10000);
		System.out.printf("%s\n","Acct Now > 10k (After Deposit)");
		saver2.calculateMonthlyInterest();
		saver2.print();
		
		saver2.withdraw(9000);
		System.out.printf("%s\n","Acct Now < 10k (After Deposit)");
		saver2.calculateMonthlyInterest();
		saver2.print();
				
	}
}
