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

package acct;

public class SpecialSavings extends SavingsAccount {

	public SpecialSavings(float sb)
	{
		super(sb);
	}
	
	public void calculateMonthlyInterest () {

		if (this.getSavingsBalance() > 10000)
		{
			this.setAnnualInterestRate(10);
			double tempBalance = (this.getSavingsBalance() * (SavingsAccount.getAnnualInterestRate()/100))/12;
			this.setSavingsBalance(this.getSavingsBalance() + (float)tempBalance);
		} else {
			this.setAnnualInterestRate(4);
			double tempBalance = (getSavingsBalance() * (SavingsAccount.getAnnualInterestRate()/100))/12;
			this.setSavingsBalance(this.getSavingsBalance() + (float)tempBalance);
		}
	}

}
