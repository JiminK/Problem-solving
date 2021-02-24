package 구현;

import java.util.*;

public class no5596 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int arr1[] = new int[4];
		int arr2[] = new int[4];
		int sum1 = 0;
		int sum2 = 0;
		int result = 0;
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == 0) {
					arr1[j] = sc.nextInt();
					sum1 += arr1[j];
				} else {
					arr2[j] = sc.nextInt();
					sum2 += arr2[j];
				}
			}
		}
		result = (sum1 >= sum2) ? sum1 : sum2; 

		System.out.println(result);
		sc.close();
	}

}
