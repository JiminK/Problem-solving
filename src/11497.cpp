#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t = 0, n = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int li[100000];
		for (int j = 0; j < n; j++) {
			cin >> li[j];
		}
		// 오름차순 정렬
		sort(li, li + n);
		int result = 0;
		for (int k = 0; k < n - 2; k++) {
			int tmp = abs(li[k + 2] - li[k]);
			result = max(result, tmp);
		}
		cout << result << endl;
	}
	return 0;
}
