package 구현;
import java.util.*;

public class no10872 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int result = N;
		
		if (N == 0)
			result = 1;
		
		for (int i = N - 1; i > 0; i--) {
			result *= i;
		}
		
		System.out.println(result);
		sc.close();
	}

}
