package 구현;

import java.util.*;

public class no5576 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arrW[] = new int[10];
		int arrK[] = new int[10];
		for (int i = 0; i < 10; i++) {
			arrW[i] = sc.nextInt();
		}
		for (int i = 0; i < 10; i++) {
			arrK[i] = sc.nextInt();
		}
		Arrays.sort(arrW);
		Arrays.sort(arrK);
		int scoreW = arrW[9] + arrW[8] + arrW[7];
		int scoreK = arrK[9] + arrK[8] + arrK[7];
		
		System.out.println(scoreW + " " + scoreK);
		sc.close();
	}

}
