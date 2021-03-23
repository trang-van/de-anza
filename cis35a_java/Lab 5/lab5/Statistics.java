/*
 * Trang Van
 * CIS 35A-61Z
 * Lab 5 - Statistics Class
 * Date Due: 07/31/2018
 * Date Submitted: 07/31/2018
 * 
 */

package lab5;

public class Statistics {
	private int[] lowscores = new int[5];

	private int[] highscores = new int[5];

	private float[] avgscores = new float[5];

	/*
	 * This method will find the lowest score and store it in an array names
	 * lowscores.
	 */

	public void findlow(Student[] a, int ct) {
		for (int i = 0; i < 5; i++) {
			int[] quizScores = a[0].getScores();
			int lowest = quizScores[i];
			for (int j = 0; j < ct; j++) {
				int[] temp = a[j].getScores();
				if (lowest > temp[i]) {
					lowest = temp[i];
				}
			}
			lowscores[i] = lowest;
		}

	}
	
	/*
	 * This method will find the highest score and store it in an array names
	 * highscores.
	 */
	public void findhigh(Student[] a, int ct) {

		for (int i = 0; i < 5; i++) {
			int quizScores[] = a[0].getScores();
			int highest = quizScores[0];
			for (int j = 1; j < ct; j++) {
				int[] temp = a[j].getScores();
				if (highest < temp[i]) {
					highest = temp[i];
				}
			}
			highscores[i] = highest;
		}
	}
	
	/*
	 * This method will find avg score for each quiz and store it in an array names
	 * avgscores.
	 */

	public void findavg(Student[] a, int ct) {

		for (int i = 0; i < 5; i++) {
			float total = 0;

			for (int j = 0; j < ct; j++) {
				int[] temp = a[j].getScores();
				total += temp[i];
			}
			avgscores[i] = total / ct;
		}
	}

	public void printLowestScores() {
		System.out.printf("%s", "Lowest Scores:  ");
		for (int l = 0; l < lowscores.length; l++) {
			System.out.printf("%-6d", lowscores[l]);

		}
	}
	
	public void printHighestScores() {
		System.out.printf("%s", "\nHighest Scores: ");
		for (int h = 0; h < highscores.length; h++) {
			System.out.printf("%-6d", highscores[h]);
		}
	}
	
	public void printAvgScores() {
		System.out.printf("%s", "\nAverage Scores: ");
		for (int a = 0; a < highscores.length; a++) {
			System.out.printf("%-6.1f", avgscores[a]);
		}
	}
}
