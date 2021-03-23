/*
 * Trang Van
 * CIS 35A - 61Z
 * Lab 2 - Store
 * Date Due: 7/18/2018
 * Date Submitted: 7/18/2018
 * 				
 */
public class Store {
	private float salesbyweek[][];
	
	public float weeklyTotal;		// function a's instance variable
	public float weeklyAverage;		// function b's instance variable
	public float totalSales;		// function c's instance variable
	public float totalAverage;		// function d's instance variable
	public int highestWeek;			// function e's instance variable
	public int lowestWeek;			// function d's instance variable
	
	Store() {
		salesbyweek = new float[5][7];
	}

	// Getter and Setters
	
	// setsaleforweekdayintersection(int week, int day, float sale)
	public void setsaleforweekdayintersection(int week, int day, float sale) {
		salesbyweek[week][day] = sale;
	}

	public float[][] getSalesbyweek() {
		return salesbyweek;
	}

	public void setSalesbyweek(float[][] salesbyweek) {
		this.salesbyweek = salesbyweek;
	}

	public void printdata() {
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				System.out.print(salesbyweek[i][j] + " ");
			}
			System.out.println("");
		}
	}
	
	// float [] getsalesforentireweek(int week)
	public float[] getsalesforentireweek(int week)
	{
		float sales[] = {};
		for (int i = 0; i < 7; i++)
		{
			sales[i] = salesbyweek[week][i];
		}
		return sales;
	}
	
	// float getsaleforweekdayintersection(int week, int day)
	public float getsaleforweekdayintersection (int week, int day)
	{
		 return salesbyweek[week][day];
	}

	// BUSINESS METHODS
	
	// a. totalsalesforweek
	public float totalsalesforweek(int week)
	{
		weeklyTotal = 0;
		for (int i = 0; i < 7; i++)
		{
			weeklyTotal += salesbyweek[week][i];
		}
		
		return weeklyTotal;
	}
	
	// b. avgsalesforweek
	public float avgsalesforweek(int week)
	{
		weeklyAverage = totalsalesforweek(week)/7;
		return weeklyAverage;
	}
	
	// c. totalsalesforallweeks
	public float totalsalesforallweeks()
	{
		totalSales = 0;
		for (int i = 0; i < 5; i ++)
		{
			totalSales += totalsalesforweek(i);
		}
		return totalSales;
	}
	
	// d. averageweeklysales
	public float averageweeklysales()
	{
		totalAverage = totalsalesforallweeks()/5;
		return totalAverage;
	}
	
	// e. weekwithhighestsaleamt
	public int weekwithhighestsaleamt()
	{
		float highestAmt;
		highestWeek =0;
		for (int i = 0; i < 5;  i++)
		{
			highestAmt = totalsalesforweek(0);
			
			if (totalsalesforweek(i) > highestAmt)
			{
				highestAmt = totalsalesforweek(i);
				highestWeek = i;
			}
		}
		return highestWeek + 1;		// Because weeks indexed from 0 to 4
	}
	
	// f. weekwithlowestsaleamt
	public int weekwithlowestsaleamt()
	{
		float lowestAmt;
		lowestWeek=0;
		for (int i = 0; i < 5;  i++)
		{
			lowestAmt = totalsalesforweek(0);

			if (totalsalesforweek(i) < lowestAmt)
			{
				lowestAmt = totalsalesforweek(i);
				lowestWeek = i;
			}
		}
		return lowestWeek + 1;
	}
	
	// analyzeresults- to call a through f
	public void analyzeresults()
	{
		for (int w = 0; w < 5; w++ )
		{
			weeklyTotal = totalsalesforweek(w);
			weeklyAverage = avgsalesforweek(w);
		}
		
		totalSales = totalsalesforallweeks();
		totalAverage = averageweeklysales();
		highestWeek = weekwithhighestsaleamt();
		lowestWeek = weekwithlowestsaleamt();	
	}
	
	// print()
	public void print(int i, int week)
	{
		switch(i)
		{
			case 0: if (week > 0)
					{
						System.out.printf("Total sales for Week %d: %.2f \n", week ,totalsalesforweek(week));
		
					}else {
						for (int w = 0; w < 5; w++ )
						{
							System.out.printf("Total sales for Week %d: %.2f \n", w+1 ,totalsalesforweek(w));
						}
					}
					
					break;
			case 1:if (week > 0)
					{
						System.out.printf("Average sales for Week %d: %.2f \n", week, avgsalesforweek(week));
					} else {
						for (int w = 0; w < 5; w++ )
						{
							System.out.printf("Average sales for Week %d: %.2f \n", w+1, avgsalesforweek(w));
						}
					}
			        break;
			case 2: System.out.printf("\n{Total sales for All Weeks: %.2f }\n", totalSales);
			        break;
			case 3: System.out.printf("{Average sales for All Weeks: %.2f }\n", totalAverage);
			        break;
			case 4: System.out.printf("{Week with highest sales: %d }\n", highestWeek);
			        break;
			case 5: System.out.printf("{Week with lowest sales: %d }\n", lowestWeek);
			        break;
		}
	}

}
