package 구현;

import java.util.*;

public class no2490 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
//		int arr[][] = new int[3][4];
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 4; j++) {
//				arr[i][j] = sc.nextInt();
//			}
//		}
//		
//		char x = 'A';
//		char y = 'A';
//		char z = 'A';
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 4; j++) {
//				int cnt = 0;
//				if (arr[i][j] == 0)
//					cnt += 1;
//				
//				
//			}
//		}
		
		int a[] = new int[4];
		int b[] = new int[4];
		int c[] = new int[4];
		int cntA = 0;
		int cntB = 0;
		int cntC = 0;
		
		for (int i = 0; i < 4; i++) {
			a[i] = sc.nextInt();
			if (a[i] == 0)
				cntA += 1;
		}
		if (cntA == 1)
			System.out.println("A");
		else if (cntA == 2)
			System.out.println("B");
		else if (cntA == 3)
			System.out.println("C");
		else if (cntA == 4)
			System.out.println("D");
		else
			System.out.println("E");
		
		for (int i = 0; i < 4; i++) {
			b[i] = sc.nextInt();
			if (b[i] == 0)
				cntB += 1;
//			System.out.println(cntB);
		}
		if (cntB == 1)
			System.out.println("A");
		else if (cntB == 2)
			System.out.println("B");
		else if (cntB == 3)
			System.out.println("C");
		else if (cntB == 4)
			System.out.println("D");
		else
			System.out.println("E");
		
		for (int i = 0; i < 4; i++) {
			c[i] = sc.nextInt();
			if (c[i] == 0)
				cntC += 1;
		}
		if (cntC == 1)
			System.out.println("A");
		else if (cntC == 2)
			System.out.println("B");
		else if (cntC == 3)
			System.out.println("C");
		else if (cntC == 4)
			System.out.println("D");
		else
			System.out.println("E");
		
		
		sc.close();
	}

}
