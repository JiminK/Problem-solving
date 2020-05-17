package 구현;
import java.util.*;
public class no10797 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); // 날짜의 일의 자리 숫자
		int cnt = 0;
		int arr[] = new int[5];
		for (int i = 0; i < 5; i++) {
			arr[i] = sc.nextInt();
			if (arr[i] == n)
				cnt += 1;
		}
		int result = cnt;
		
		System.out.println(result);
		sc.close();
	}

}
