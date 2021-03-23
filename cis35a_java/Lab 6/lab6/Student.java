/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 5 - Student Class
 * Date Due: 07/31/2018
 * Date Submitted: 07/31/2018
 * 
 */

package lab6;

import java.io.Serializable;

public class Student implements Serializable {
	private static final long serialVersionUID = 1L;

	private int SID;

	private int scores[] = new int[5];

	
	// write public get and set methods for
	// SID and scores
	public Student() {}
	
	public Student(int sID, int[] scores) {
		super();
		SID = sID;
		this.scores = scores;
	}

	public int getSID() {
		return SID;
	}

	public void setSID(int sID) {
		SID = sID;
	}

	public int[] getScores() {
		return scores;
	}

	public void setScores(int[] scores) {
		this.scores = scores;
	}

	// add methods to print values of instance variables.
	
	public void printStudentData ()
	{
		System.out.printf("%4d%5d%5d%5d%5d%5d\n", SID, scores[0], scores[1], scores[2], scores[3], scores[4]);
		System.out.println();
	}
}
