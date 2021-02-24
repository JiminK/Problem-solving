package 단계1;
import java.util.*;

public class no2588 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int tmp = b;
		//int arrA[] = new int[3];
		int arrB[] = new int[3];
		for (int i = 2; i >= 0; i--) {
			//arrA[i] = a % 10;
			arrB[i] = tmp % 10;
			//a = a / 10;
			tmp /= 10;
		}
		
		int l = a * arrB[2];
		int m = a * arrB[1];
		int n = a * arrB[0];
		int k = a * b;
				
		System.out.println(l);
		System.out.println(m);
		System.out.println(n);
		System.out.println(k);
		sc.close();
	}

}
