package 구현;

import java.util.*;

public class no5597 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[] = new int[28];
		for (int i = 0; i < 28; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		int arr2[] = new int[28];
		
		if (arr[0] != 1)
			arr2[0] = 1;
		if (arr[27] != 30)
			arr2[1] = 30;
		else {
			for (int i = 0; i < 28; i++) {
				if (i == 27)
					break;
				else if ((arr[i + 1] - arr[i]) != 1) 
					arr2[i] = arr[i] + 1;
				
			}
		}
		
		for (int i = 0; i < 28; i++) {
			if (arr2[i] != 0)
				System.out.println(arr2[i]);
		}
		sc.close();
	}

}
