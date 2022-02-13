#include <iostream>
using namespace std;

#define MAX_N 20 + 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int halfN = n / 2;
    int sij[MAX_N][MAX_N] = {0};

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            cin >> sij[i][j];
        }
    }

    int sTeam = 0, lTeam = 0;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            

        }
    }

    return 0;
}