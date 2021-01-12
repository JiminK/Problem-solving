#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0;
	vector<int> rope(N);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		rope.push_back(a);
	}
	sort(rope.begin(), rope.end()); // 오름차순

	vector<int> result(N);
	for (int i = 0; i < N; i++)
		result[i] = rope[i] * (rope.size() - i);
	
	int max = *max_element(result.begin(), result.end());
	cout << max << endl;

	return 0;
}
