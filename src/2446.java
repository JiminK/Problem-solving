package 단계5;
import java.util.*;

public class no2446 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++)
				System.out.print(" ");
			for (int j = n - i; j >= 0; j--)
				System.out.print("*");
			for (int j = n - i; j > 0; j--)
				System.out.print("*");
//			for (int j = 1; j < i; j++)
//				System.out.print(" ");
			System.out.println();
		}
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 1; j < i; j++)
				System.out.print(" ");
			for (int j = n - i; j >= 0; j--)
				System.out.print("*");
			for (int j = n - i; j > 0; j--)
				System.out.print("*");
//			for (int j = 1; j < i; j++)
//				System.out.print(" ");
			System.out.println();
		}
		
		
		sc.close();
	}
}
