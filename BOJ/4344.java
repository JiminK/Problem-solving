package 단계6;
import java.util.*;
public class no4344 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int C = sc.nextInt(); // 테스트 개수
		for (int i = 0; i < C; i++) {
			int N = sc.nextInt();
			float arr[] = new float[N];
			float sum = 0;
			for (int j = 0; j < N; j++) {
				arr[j] = sc.nextInt();
				sum += arr[j];
			}
			float avg = sum / N;
//			System.out.println(avg);
			float cnt = 0;
			for (int j = 0; j < N; j++) {
				if (arr[j] > avg) {
					cnt += 1;
				}
		
			}
			float result = (cnt / N) * 100;
//			System.out.println(cnt);
			System.out.print(String.format("%.3f", result));
			System.out.println("%");
			
		}
		
		sc.close();
	}

}
