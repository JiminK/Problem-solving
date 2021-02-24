package 구현;

import java.util.*;

public class no4153 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tmp = 1;
		int arr[] = new int[3];
		while (tmp != 0) {
			for (int i = 0; i < 3; i++)
				arr[i] = sc.nextInt();
			Arrays.sort(arr);
			tmp = arr[0];
			if (tmp == 0) {
				break;	
			}
			else {
				if (Math.pow(arr[2], 2) == Math.pow(arr[0], 2) + Math.pow(arr[1], 2))
					System.out.println("right");
				else
					System.out.println("wrong");
			}

		}

		sc.close();
	}

}
