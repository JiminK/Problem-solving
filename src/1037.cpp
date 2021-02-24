#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num; // 약수의 개수
	cin >> num;

	int arr[50] = { 0 }; // 약수
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + num);
	cout << arr[0] * arr[num - 1] << endl;

	return 0;
}