#include <iostream>
#include <vector>

using namespace std;

int N, K, M;
int P = -1;
vector<int> gimbab;

void solve() {
    if (gimbab.empty()) return;

    // M 이 최소값인 1일 때, L 이 최대값인 10^9 이므로, P 의 최대값은 10^9 이다.
    int left = 1, right = 1000000000;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i=0; i<gimbab.size(); ++i) {
            cnt += gimbab[i] / mid;
        }
        if (cnt >= M) {
            P = mid;
            left = mid + 1;
        }
        else { // else if (cnt < M)
            right = mid - 1;
        }
    }
}

void getInput() {
    cin >> N >> K >> M;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        if (temp < K) continue;
        if (temp < 2*K) {
            temp -= K;
            gimbab.push_back(temp);
            continue;
        }
        temp -= 2*K;
        if (temp == 0) continue;
        gimbab.push_back(temp);
    }
    solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << P << "\n";

    return 0;
}

// 참고: https://ps-ps-ps.tistory.com/121 