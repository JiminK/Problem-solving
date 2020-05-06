package 구현;
import java.util.*;

public class no5543 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int result = 0;
		
		if (a <= b) {
			if (a <= c)
				result = a;
			else 
				result = c;
		} else if (a > b) {
			if (b <= c)
				result = b;
			else
				result = c;
		}
		if (x < y)
			result += x;
		else
			result += y;
		
		System.out.println(result - 50);
		sc.close();
	}

}
