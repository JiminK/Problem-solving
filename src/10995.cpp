#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int k = 0; k < n; k++) {
				for (int j = 0; j < 1; j++) {
					cout << "*";
				}
				for (int j = 0; j < 1; j++) {
					cout << " ";
				}
			}
		}
		else {
			for (int k = 0; k < n; k++) {
				for (int j = 0; j < 1; j++) {
					cout << " ";
				}
				for (int j = 0; j < 1; j++) {
					cout << "*";
				}
			}
		}
		cout << endl;
	}

	return 0;
}