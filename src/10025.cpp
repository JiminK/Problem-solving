/* 
   "크기가 고정된 구간의 합"을 구할 때는
   구간의 크기만큼 합을 구하고,                       -> i=0 부터 i=(구간의 크기) 까지 sum += arr[i]
   인덱스를 증가시키면서                              -> ++i 
   (현재 인덱스 - 구간의 크기)의 인덱스의 값을 빼고   -> sum -= arr[i - (구간의 크기 + 1)]
   현재 인덱스의 값을 더한다.                         -> sum += arr[i]
   *** 투 포인터 쓰지 않는다!!!
*/
#include <iostream>

#define MAX_X 1000000 // coord MAX
#define MAX_N 100000  // bucket num MAX

using namespace std;

int N, K;
int coord[MAX_X + 1]; // 좌표 
long long maxSum;

void solve() {
    long long sum = 0;
    for (int i=0; i<=MAX_X; ++i) {
        if (i < 2*K + 1) {
            sum += coord[i];
            if (maxSum < sum) maxSum = sum;
            continue;
        }
        sum -= coord[i - (2*K + 1)];
        sum += coord[i];
        if (maxSum < sum) maxSum = sum;
    }
}

void getInput() {
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        int gi, xi; cin >> gi >> xi;
        coord[xi] = gi;
    }
    solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << maxSum << "\n";

    return 0;
}