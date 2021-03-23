
/*
 * Trang Van
 * CIS 35A
 * 
 * Lab 1 Part 1
 * 
 */

import java.util.Scanner;

public class Lab1Pt1 {

	static Scanner a1 = new Scanner(System.in);

	public static void main(String[] args) {

		double loanAmt, rate, monthlyRate; // Stores loan amount and annual interest rate
		int years = 0; // Stores amount of time loan is going to be paid

		System.out.printf("%s", "Loan Amount: ");
		loanAmt = a1.nextDouble();

		System.out.printf("%s", "Number of years: ");
		years = a1.nextInt();

		System.out.printf("%s", "Annual Interest Rate: ");
		rate = a1.nextDouble();

		monthlyRate = rate / 1200; // Convert annual percentage to a decimal for 12 months in a year

		// Monthly Payment - Formula found on pg.60
		// Uses loanAmt, monthlyRate, and years to calculate amount due each month
		double monthlyPayment = loanAmt * monthlyRate / (1 - 1 / Math.pow(1 + monthlyRate, years * 12));
		System.out.printf("\nMonthly Payment: %.2f", monthlyPayment);

		// Total Payment - Formula found on pg.60
		double totalPayment = calcTotalPayment(monthlyPayment, years);
		System.out.printf("\nTotal Payment: %.2f", totalPayment);

		displayTable(years, loanAmt, monthlyRate, monthlyPayment);

	}

	public static double calcTotalPayment(double mp, int y) {
		// mp -> monthly payment and y -> years
		return mp * y * 12;
	}

	public static void displayTable(int years, double loanAmt, double monthlyRate, double monthlyPayment) {
		double monthlyInterest = 0, principle = 0;
		System.out.printf("\n\n%-15s%-15s%-23s%-15s", "Payment#", "Interest", "Principle", "Balance");
		for (int i = 1; i <= years * 12; i++) {
			monthlyInterest = loanAmt * monthlyRate;
			principle = monthlyPayment - monthlyInterest;
			loanAmt -= principle;

			System.out.printf("\n%-15d%-15.2f%-15.2f%15.2f", i, monthlyInterest, principle, loanAmt);
		}
	}

}
