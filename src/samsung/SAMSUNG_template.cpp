#include <iostream>

using namespace std;

int T, N, result;

void solve() {

}

void init() {

}

void getInput() {
	cin >> T >> N;
	for (int i = 0; i < T; ++i) {
		cin >> N;

		solve();
		cout << result << "\n";

		init();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	getInput();


	return 0;
}