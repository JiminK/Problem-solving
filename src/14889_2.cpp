#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 20 + 2

void combination(vector<int> v, vector<int> c, int r, int idx, int depth) {
    if (r == 0) {
        // cout << cnt + 1 << " : ";
        for (int i = 0; i < c.size(); ++i) {
            cout << c[i] << " ";
        }
        cout << "\n"; 
        // cnt++;
    } else if (depth == v.size()) {
        return;
    } else {
        c[idx] = v[depth];
        combination(v, c, r - 1, idx + 1, depth + 1);
        combination(v, c, r, idx, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int halfN = n / 2;
    vector< vector<int> > sij(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sij[i][j] << " ";

        }
        cout << "\n";
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> sij[i][j];
        }
    }

    int sTeam = 0, lTeam = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sij[i][j] << " ";

        }
        cout << "\n";
    }

    return 0;
}