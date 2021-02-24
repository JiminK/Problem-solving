package 구현;

import java.util.*;

public class no5565 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sum = 0;
		int arr[] = new int[10];
		for (int i = 0; i < 10; i++) {
			arr[i] = sc.nextInt();
			sum += arr[i];
		}
		int result = 0;
		result = arr[0] - (sum - arr[0]);

		System.out.println(result);
		sc.close();
	}

}
