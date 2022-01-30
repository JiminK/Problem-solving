#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> cards;
    for (int i = 0; i < n; ++i) {
        int tmp = 0; cin >> tmp;
        cards.push_back(tmp);
    }

    int sum = 0;
    int minNum = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				sum = cards[i] + cards[j] + cards[k];
				if (sum <= m && sum > minNum) {
					minNum = sum;
				}
			}
		}
	}
    cout << minNum << "\n";
    return 0;
}

/* 브루트포스 */