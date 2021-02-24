package 구현;
import java.util.*;

public class no10039 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();
		int e = sc.nextInt();
		
		if (a < 40)
			a = 40;
		if (b < 40)
			b = 40;
		if (c < 40)
			c = 40;
		if (d < 40)
			d = 40;
		if (e < 40)
			e = 40;
		
		int sum = a + b + c + d + e;
		int avg = sum / 5;
		
		System.out.println(avg);
		sc.close();
	}

}
