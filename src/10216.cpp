/*
연결요소 개수 문제
(통신이 가능하다 = 연결되어 있다)
인접리스트 사용
---
또는 union-find 로 풀 수 있다. O(N^2) 만에 풀 수 있다.
*/
#include <iostream>

#define MAX_XY 5000
#define MAXN 3000

using namespace std;

int T, N, X, Y, R;
struct strt {
    int x, y;
    int r;
};
int G[MAX_XY + 1][MAX_XY + 1];

void solve() {

}

void init() {

}

void getInput() {
    cin >> T;
    for (int i=0; i<T; ++i) {
        cin >> N;
        for (int j=0; j<N; ++j) {
            cin >> X >> Y >> R;
            G[X][Y] = R;
        }

        solve();
        init();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}