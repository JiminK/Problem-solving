package 단계4;
import java.util.*;
public class no10952 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = 0;
		int b = 0;
		while (true) {
			a = sc.nextInt();
			b = sc.nextInt();
			if (a != 0 && b != 0)
				System.out.println(a + b);
			else
				break;
			
		}
		
		sc.close();
	}

}
