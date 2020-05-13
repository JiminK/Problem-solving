package 수학;
import java.util.*;

public class no2010 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); // 멀티탭 개수
		int arr[] = new int[N];
		int result = 0;
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
			result += arr[i];
		}
		
		System.out.println(result - (N - 1));
		sc.close();
	}

}
