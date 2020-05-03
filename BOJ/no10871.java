package 구현;
import java.util.ArrayList;
import java.util.Scanner;

public class no10871 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		ArrayList less = new ArrayList();
		
		for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			if (a < X)
				less.add(a);
			else
				continue;
		}
		
		for (int i = 0; i < less.size(); i++) {
			System.out.print(less.get(i) + " ");
		}
		
		sc.close();
		
	}

}
