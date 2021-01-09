#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int arr[11] = { 0 };
int maxR = INT_MIN, minR = INT_MAX;

// recursive call 사용
void calc(int add, int subt, int mult, int div, int cnt, int result) {
    // 종료 조건
    if (cnt == N - 1) {
        maxR = max(maxR, result);
        minR = min(minR, result);
//      cout << maxR << endl;
//      cout << minR << endl;
    }
    
    if (add > 0)
        calc(add - 1, subt, mult, div, cnt + 1, result + arr[cnt + 1]);
    if (subt > 0)
        calc(add, subt - 1, mult, div, cnt + 1, result - arr[cnt + 1]);
    if (mult > 0)
        calc(add, subt, mult - 1, div, cnt + 1, result * arr[cnt + 1]);
    if (div > 0)
        calc(add, subt, mult, div - 1, cnt + 1, result / arr[cnt + 1]);
    
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int add, subt, mult, div;
    cin >> add >> subt >> mult >> div;

    calc(add, subt, mult, div, 0, arr[0]);
    cout << maxR << endl;
    cout << minR << endl;

    return 0;
}