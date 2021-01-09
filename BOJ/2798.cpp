#include <iostream>
#include <climits>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int arr[100] = { 0 };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int min = INT_MIN;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= M && min < sum) {
					min = sum;
				}
					
			}
		}
	}
	cout << min << endl;

	return 0;
}