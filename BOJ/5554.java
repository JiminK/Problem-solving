package 구현;

import java.util.*;

public class no5554 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			int a = sc.nextInt();
			sum += a;
		}
		int x, y;
		x = sum / 60;
		y = sum % 60;
		
		System.out.println(x);
		System.out.println(y);
		sc.close();
	}

}
