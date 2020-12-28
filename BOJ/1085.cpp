// 조건을 보면 알겠지만(x, y의 범위),
// 현수는 직사각형 안에 있는 거.
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int arr[4] = { 0 };
	arr[0] = x;
	arr[1] = y;
	arr[2] = w - x;
	arr[3] = h - y;

	sort(arr, arr + 4);
	cout << arr[0] << endl;

	return 0;
}