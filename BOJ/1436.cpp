#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int result = 0, cnt = 0, i = 666;

	while (cnt != N) {
		int tmp = i;
		while (tmp != 0) {
			int a = 0;
			a = tmp % 1000;
			tmp /= 10;
			if (a == 666) {
				result = i;
				cnt++;
				break;
			}
		}
		i++;
	}
	cout << result << endl;

	return 0;
}