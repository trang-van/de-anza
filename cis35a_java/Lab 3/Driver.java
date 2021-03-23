
/*
 * Trang Van
 * CIS 35A - 61Z
 * Lab 2 - Driver
 * Date Due: 7/18/2018
 * Date Submitted: 7/18/2018
 * 				
 */

import java.util.Scanner;

public class Driver {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FileIO a1 = new FileIO("C:\\Users\\Trang\\eclipse-java-workspace\\Assignment 3\\Salesdat.txt");
		System.out.print("============== PART 1- READING FROM FILE ===============\n\n");
		Franchise f = a1.readData();
		System.out.println();

		// Print Calculations for All Stores
		System.out.print("\n\n============== PART 2- ALL CALCULATIONS ===============\n\n");

		for (int i = 0; i < 6; i++)
		{
			Store s = f.getStores(i);
			System.out.printf("\n++++ Store %d ++++\n\n", i+1);
			for (int j = 0; j < 6; j ++)
			{	
				s.analyzeresults();
				s.print(j,-1);		// Second parameter to let user specify week, otherwise for all, use parameter < 0 
			}
		}
		
		// User Interface - utilizes Franchise and Store class (print)
		System.out.print("\n\n============== PART 3- USER INTERFACE ===============");

		int storeNum = 0, choice= 0;		// For user input
		Store s;						
		
		System.out.printf("\n\n%s\n", "--- WELCOME TO THE STORE SALES ANALYSIS ---");

		do
		{
			System.out.printf("%s", "Please enter a Store # or enter -1 to Quit: ");
			storeNum = input.nextInt();
			String strClear = input.nextLine(); // pending CRLF in buffer that has to be read
			if (storeNum == -1) 
			{
				break;
			}
			
			while (storeNum > 6)
			{
				System.out.printf("%s", "STORE NOT FOUND!\nPlease enter a Store # or enter -1 to Quit: ");
				storeNum = input.nextInt();
			}
			
			s = f.getStores(storeNum-1);
			
			do 
			{
				System.out.printf("\n++++++ STORE #%d ++++++\n", storeNum);

				// Display Menu Options
				System.out.printf("\n%s\n", "==== View Available Statistics ===");
				System.out.printf("%s\n", "1. Total Sales for Week");
				System.out.printf("%s\n", "2. Average Sales for Week");
				System.out.printf("%s\n", "3. Total Sales for All Weeks");
				System.out.printf("%s\n", "4. Average Sales for All Weeks");
				System.out.printf("%s\n", "5. Week with Highest Sales");
				System.out.printf("%s\n", "6. Week with Lowest Sales");
				System.out.printf("%s\n", "7. Go back");
				
				System.out.printf("%s\n", ">> Enter what you want to see today: ");
				choice = input.nextInt();
				String strClear2 = input.nextLine(); // pending CRLF in buffer that has to be read

				int week = 0;
				if (choice == 1 || choice == 2)
				{
					do
					{
						System.out.printf("%s\n", ">>Enter which week you want to see (up to 5 weeks): ");
						week = input.nextInt();
						String strClear3 = input.nextLine(); // pending CRLF in buffer that has to be read

					} while (week > 5);
				}
				s.print(choice-1,week-1);

			} while (choice < 7);
			
		} while (storeNum != -1);	
	}
}

