/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 5 - Util Class
 * Date Due: 07/31/2018
 * Date Submitted: 07/31/2018
 * 
 */

package lab5;

import java.io.*;
import java.util.*;

public class Util {
	// Use ReadSource.java
	
	public static int studentCt;	// Keeps track of how many students there are 
	
	public static Student[] readFile(String filename, Student[] stu) {
		int lineCt = 0;
		int studentIndex =0;

		// Reads the file and builds student array.

		// Open the file using FileReader Object.
		try {
			FileReader file = new FileReader("C:\\Users\\Trang\\eclipse-java-workspace\\Assignment 5\\studentData.txt");

			BufferedReader buff = new BufferedReader(file);

			boolean eof = false;

			while (!eof) {
				// In a loop read a line using readLine method.
				String line = buff.readLine();
				lineCt++;
				
				if (line == null) {
					eof = true;
				} else if (lineCt == 1)
				{
					String headerBuf = line; 		// Store header Stud Q1..etc to ignore				
				} else if (line.length() == 0) {
					continue;
				} else {	
					// Tokenize each line using StringTokenizer Object
					// Each token is converted from String to Integer using parseInt method }
					// Value is then saved in the right property of Student Object.
					
					String s1 = "";
					int[] scoresArr = new int[5];
					int x = 0;
					stu[studentIndex] = new Student();		//initialize new Student obj for each student
					
					StringTokenizer st = new StringTokenizer(line);
					while (st.hasMoreTokens()) {
						s1 = st.nextToken();
						x = Integer.parseInt(s1);

						stu[studentIndex].setSID(x);
						for (int i = 0; i < 5; i++) {
							s1 = st.nextToken();
							x = Integer.parseInt(s1);
							scoresArr[i] = x;
						}
						
						stu[studentIndex].setScores(scoresArr);
					}
					studentIndex++;
				}
			}
			
			buff.close();
		} catch (IOException e) {
			System.out.println("Error -- " + e.toString());
		}
		
		studentCt = studentIndex;
		return stu;
	}
}
