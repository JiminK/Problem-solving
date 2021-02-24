package 구현;
import java.util.*;

public class no10886 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); // 사람 수
		int arr[] = new int[N];
		int cnt0 = 0, cnt1 = 0;
		
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
			if (arr[i] == 0)
				cnt0 += 1;
			else if (arr[i] == 1)
				cnt1 += 1;
		}
		if (cnt0 > cnt1)
			System.out.println("Junhee is not cute!");
		else
			System.out.println("Junhee is cute!");
		
		sc.close();
	}

}
