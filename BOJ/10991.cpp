#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++)
			cout << " ";
		for (int j = n - 1 - i; j < n + i; j++) {
			if (n % 2 != 0) {
				if (i % 2 != 0) {
					if (j % 2 != 0)
						cout << "*";
					if (j % 2 == 0)
						cout << " ";
				}
				if (i % 2 == 0) {
					if (j % 2 != 0)
						cout << " ";
					if (j % 2 == 0)
						cout << "*";
				}
			}
			if (n % 2 == 0) {
				if (i % 2 == 0) {
					if (j % 2 != 0)
						cout << "*";
					if (j % 2 == 0)
						cout << " ";
				}
				if (i % 2 != 0) {
					if (j % 2 != 0)
						cout << " ";
					if (j % 2 == 0)
						cout << "*";
				}
			}
		}
		cout << endl;
	}
	return 0;
}
