import java.util.Scanner;

/*
 * Trang Van
 * CIS 35A
 * 
 * Lab 1 Part 2
 * 
 */

public class Lab1Pt2 {
	
	static Scanner a1 = new Scanner(System.in);
	
	public static void main(String[] args) {
		System.out.printf("%s", "=== Approximate the Square Root === ");
		
		long num;
		do
		{
			System.out.printf("\n%s", "Enter a number: ");
			num = a1.nextLong();
			
			// Error Check if num < 0 or Negative
			if (num < 0) { System.out.printf("\n%s", "Can't have root of a negative number. Try again.\n");}
		} while (num < 0);
		
		
		double approxSqRt = sqrt(num);
		System.out.printf("\nThe approximate square root of %d is %.4f.",num, approxSqRt);
	}
	
	// Function that applies Babylonian Method 
	public static double sqrt (long n)
	{
		double lastGuess = 1, nextGuess = 0.0;
		double precision = 0.00001;
		double difference;
		
		do
		{
			nextGuess = (lastGuess + n / lastGuess) /2;
			//System.out.printf("\nNext Guess: %.4f", nextGuess); 		//Test Output

			difference = absValue(nextGuess-lastGuess);
			//System.out.printf("\n DIFF: %.4f", difference);			//Test Output

			lastGuess = nextGuess;
		}while(difference > precision);
		
		return nextGuess;
	}
	
	
	// Function to make ensure the difference comparison is with positive numbers
	// 		otherwise, the loops won't run properly
	public static double absValue(double d)
	{
		if (d < 0)
		{
			return -d;
		}
		
		return d;
	}
}
