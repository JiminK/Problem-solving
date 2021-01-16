#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	vector<int> v(n);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i] << "\n"; // endl로 하면 시간초과. (왜?)

	return 0;
}
