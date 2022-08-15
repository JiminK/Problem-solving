#include <iostream>

#define MAX_K 10000

using namespace std;

int K, N;
long long ans;
long long line[MAX_K + 1];

void solve(long long maxi) {
    long long left = 1, right = maxi;
    while (left <= right) {
        long long mid = (left + right) / 2;
        int sum = 0;
        // 끈 길이를 mid 로 나는 몫(=mid 길이로 끈을 잘랐을 때 얻을 수 있는 끈의 개수)
        for (int i=0; i<K; ++i) {
            sum += line[i] / mid;
        }
        // 얻어진 끈의 개수가 원하는 끈의 개수(=N)보다 많으면
        if (sum >= N) {
            // mid 보다 더 긴 길이로 잘랐을 때도 N개 이상 얻을 수 있는지 확인해야함.
            left  = mid + 1;
            // 더 큰 값으로 답 갱신 
            ans = max(ans, mid);
        }
        // 얻어진 끈의 개수가 원하는 끝의 개수(=N)보다 적으면 
        else { // else if (sum < N)
            // mid 보다 더 짧은 길이로 잘랐을 때 가능한지 확인해야함.
            right = mid - 1;
        }
    }
}

void getInput() {
    cin >> K >> N;
    long long maxi = -1;
    for (int i=0; i<K; ++i) {
        cin >> line[i];
        maxi = max(maxi, line[i]);
    }
    solve(maxi);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << ans << "\n";

    return 0;
}