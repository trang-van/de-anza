/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 5 - Driver
 * Date Due: 07/31/2018
 * Date Submitted: 07/31/2018
 * 
 */

package lab5;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student lab2 [] = new Student[40];

		//Populate the student array

		lab2 = Util.readFile("C:\\Users\\Trang\\eclipse-java-workspace\\Assignment 5\\studentData.txt", lab2);
		int studCt = Util.studentCt;
		
		// Print all student ID's and scores
		System.out.printf("%s","Stud   Q1   Q2   Q3   Q4   Q5\n\n");
		for (int i = 0; i < studCt ; i++)
		{
			lab2[i].printStudentData();
		}
		
		// Calculate and print statistics for each quiz
		Statistics statlab2 = new Statistics();

		statlab2.findlow(lab2, studCt);
		statlab2.findhigh(lab2, studCt);
		statlab2.findavg(lab2, studCt);

		statlab2.printLowestScores();
		statlab2.printHighestScores();
		statlab2.printAvgScores();
	}
}
