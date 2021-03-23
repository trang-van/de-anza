package lab6;

import java.io.Serializable;

public class StudentStat implements Serializable {
	private Student s1; //holds data for one students.
	private Statistics stat; //holds statistics for entire class.

	public StudentStat() {}
	public StudentStat(Student s1, Statistics stat) {
		super();
		this.s1 = s1;
		this.stat = stat;
	}
	public Student getS1() {
		return s1;
	}
	public void setS1(Student s1) {
		this.s1 = s1;
	}
	public Statistics getStat() {
		return stat;
	}
	public void setStat(Statistics stat) {
		this.stat = stat;
	}
	
	public void print() {
		stat.printAvgScores();
		stat.printHighestScores();
		stat.printLowestScores();

	}
}
