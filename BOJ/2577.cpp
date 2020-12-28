#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	
	int num = a * b * c;
//	cout << num << endl;
	int arr[10] = { 0 };

	while (num > 0) {
		int x = num % 10;
//		cout << x << endl;
		arr[x]++;
//		cout << arr[x] << endl;
		num /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;
	return 0;

}
