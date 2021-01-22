#include <iostream>
using namespace std;

int arr[3][2];
int x = 0, y = 0;

int main() {
	for (int i = 0; i < 3; i++) 
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (arr[i][0] != arr[j][0]) {
				continue;
			}
			if (arr[i][0] == arr[j][0]) {
				arr[i][0] = -1;
				arr[j][0] = -1;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (arr[i][1] != arr[j][1]) {
				continue;
			}
			if (arr[i][1] == arr[j][1]) {
				arr[i][1] = -1;
				arr[j][1] = -1;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (arr[i][0] != -1)
			x = arr[i][0];
		if (arr[i][1] != -1)
			y = arr[i][1];
		else
			continue;
	}

/*
	for (int i = 0; i < 3; i++) {
		cout << arr[i][0] << " " << arr[i][1] << endl;
	}
*/
	cout << x << " " << y << endl;
	return 0;
}