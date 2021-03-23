/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 4- Exercise 1 Pt. 1
 * Date Due: 07/23/2018
 * Date Submitted: 07/23/2018
 * 
 */

package acct;

public class SavingsAccount {

	private static double annualInterestRate;
	private float savingsBalance;
	
	public SavingsAccount() {}
	public SavingsAccount(float savingsBalance) {
		this.savingsBalance = savingsBalance;
	}

	// Getters & Setters
	protected float getSavingsBalance() {
		return savingsBalance;
	}

	protected void setSavingsBalance(float savingsBalance) {
		this.savingsBalance = savingsBalance;
	}
	
	protected static double getAnnualInterestRate() {
		return annualInterestRate;
	}

	protected static void setAnnualInterestRate(double annualInterestRate) {
		SavingsAccount.annualInterestRate = annualInterestRate;
	}

	// Calculation Methods
	public void calculateMonthlyInterest () {
		savingsBalance += savingsBalance * (annualInterestRate/100) / 12;
	}
	
	public static void modifyInterestRate (float newRate) {
		annualInterestRate = newRate;
	}
	
	public void deposit(float amount)
	{
		savingsBalance += amount;
	}
	
	public void withdraw(float amount)
	{
		savingsBalance -= amount;
	}
	
	public void print() {
		System.out.printf("Annual Interest Rate: %.2f\nNew Balance: %.2f\n\n", annualInterestRate, savingsBalance);
		
	}
	
}
