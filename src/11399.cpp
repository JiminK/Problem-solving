#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0, result = 0;
	cin >> N;
	vector<int> pi(N);
	for (int i = 0; i < N; i++)
		cin >> pi[i];

	sort(pi.begin(), pi.end()); // 오름차순

	for (int i = 0; i < N; i++) {
		result += pi[i] * (N - i);
	}
	//for (int i = 0; i < N; i++)
	//	for (int j = 0; j <= i; j++)
	//		result += pi[j];

	cout << result << endl;

	return 0;
}