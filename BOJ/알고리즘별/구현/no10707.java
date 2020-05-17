package 구현;

import java.util.*;

public class no10707 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[] = new int[5];
		for (int i = 0; i < 5; i++) {
			arr[i] = sc.nextInt();
		}
		int x = 0;
		int y = 0;
		x = arr[0] * arr[4];
		if (arr[4] < arr[2])
			y = arr[1];
		else if (arr[4] >= arr[2])
			y = arr[1] + (arr[4] - arr[2]) * arr[3];	
		
		int result = (x >= y) ? y : x;
//		System.out.println(x + ", " + y);
		System.out.println(result);
		sc.close();

	}

}
