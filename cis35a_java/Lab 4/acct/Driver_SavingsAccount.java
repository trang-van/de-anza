package acct;
/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 4- Exercise 1 Pt. 1
 * Date Due: 07/23/2018
 * Date Submitted: 07/23/2018
 * 
 *
 */
import acct.*;

public class Driver_SavingsAccount {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		SavingsAccount saver1  = new SavingsAccount(2000);
		SavingsAccount saver2  = new SavingsAccount(3000);
		
		SavingsAccount.setAnnualInterestRate(4);
		
		System.out.printf("%s\n", "SAVER 1");

		saver1.calculateMonthlyInterest();
		saver1.print();
				
		System.out.printf("Withdrew: %s\n", "$5000");
		saver1.deposit(5000);		// balance now 2006.67 +5000 =7006.67
		saver1.calculateMonthlyInterest();
		saver1.print();
		
		System.out.printf("%s\n", "SAVER 2");

		saver2.calculateMonthlyInterest();
		saver2.print();
		
		System.out.printf("Withdrew: %s\n", "$500");
		saver2.withdraw(500);
		saver2.calculateMonthlyInterest();
		saver2.print();
		
		SavingsAccount.setAnnualInterestRate(5);
		
		System.out.printf("----\n%s\n", "SAVER 1");
		saver1.calculateMonthlyInterest();
		saver1.print();
		
		System.out.printf("Withdrew: %s\n", "$1300");
		saver2.withdraw(1300);
		saver2.calculateMonthlyInterest();
		saver2.print();
		
		System.out.printf("%s\n", "SAVER 2");
		saver2.calculateMonthlyInterest();
		saver2.print();
	
		System.out.printf("Deposit: %s\n", "$15000");
		saver2.deposit(15000);
		saver2.calculateMonthlyInterest();
		saver2.print();
		
	}

}
