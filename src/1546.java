package 단계6;

import java.util.*;

public class no1546 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); // 과목 개수
		double arr[] = new double[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextDouble();
//			System.out.println("arr[i]: " + arr[i]);
		}
		Arrays.sort(arr);
		double m = arr[n - 1]; // 최댓값
//		System.out.println("m: " + m);
		
		double sum = 0;
		double arr2[] = new double[n];
		for (int i = 0; i < n; i++) {
			double a = arr[i] / m;
//			System.out.println(a);
			arr2[i] = a * 100;
//			System.out.println("arr2[i]: " + arr2[i]);
			sum += arr2[i];
//			System.out.println("sum: " + sum);
		}
		
		double avg = sum / n;
		System.out.println(avg);
		sc.close();
	}

}
