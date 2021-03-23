/*
 * Trang Van
 * CIS 35A - 61Z
 * Lab 2 Pt 1 - Coin Driver
 * Date Due: 7/13/2018
 * Date Submitted: 7/13/2018
 * 
 * Description: Creates coin objects and generates a toss: heads or tails
 *				Program counts the number of times heads or tails have been tossed.
 * 
 */
public class Driver {

	public static void main(String arg[]) {
		Coin quarter = new Coin();
		Coin dime = new Coin();
		Coin nickel = new Coin();

		Simulation coinToss = new Simulation();

		System.out.printf("+++ %s +++\n", "Quarter Toss:");
		coinToss.toss(quarter);
		System.out.printf("\n\n+++ %s +++\n", "Dime Toss:");
		coinToss.toss(dime);
		System.out.printf("\n\n+++ %s +++\n", "Nickel Toss:");
		coinToss.toss(nickel);
	}

}
