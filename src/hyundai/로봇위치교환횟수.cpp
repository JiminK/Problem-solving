#include <iostream>

#define MAXN 200000

using namespace std;

int N;
int robot[MAXN+1];
int maxi, mini;

void solve() {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N-1-i; ++j) {
            if (robot[j] >= robot[j+1]) {
                if (robot[j] == robot[j+1])
                    maxi++;
                else {
                    maxi++;
                    mini++;
                }
                int temp = robot[j];
                robot[j] = robot[j+1];
                robot[j+1] = temp;
            }
        }
    }
}

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> robot[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();
    cout << mini << " " << maxi << "\n";

    return 0;
}