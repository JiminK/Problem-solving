#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	int c = 0;
	
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		
		//if (a == 1)
		//	continue;
		if (a > 1)
		{
			for (int j = 2; j <= a; j++)
			{
				if (a % j == 0)
					c++;
			}
			if (c == 1)
				cnt++;	
				
			c = 0;	
		}
	}
	cout << cnt << endl;
	
	return 0;
}
