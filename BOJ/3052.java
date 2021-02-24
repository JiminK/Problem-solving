package 단계6;
import java.util.*;
public class no3052 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[] = new int[10];
		int num = 1;
		for (int i = 0; i < 10; i++) {
			arr[i] = sc.nextInt() % 42;
		}
		Arrays.sort(arr);
		for (int i = 1; i < 10; i++) {
			if (arr[i] != arr[i - 1]) {
				num += 1;
			} else
				continue;
		}
		System.out.println(num);
		sc.close();
	}

}
