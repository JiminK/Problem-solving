#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
	int result = 0, cnt = 0, num = 666;
	
	while (cnt != n) { 
		int tmp = num;
		while (tmp != 0) {
			int a = tmp % 1000;
			if (a == 666) {
				result = num;
				cnt++;
				break;
			}
            tmp /= 10;
		}
		num++;
	}
	cout << result << "\n";
    return 0;
}