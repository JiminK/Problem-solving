#include <iostream>
#include <vector>

using namespace std;

// int cnt = 0;
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

    int n, m; cin >> n >> m;
    vector<int> v(n), c(m);
    for (int i = 1; i <= n; ++i) {
        v[i - 1] = i;
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << v[i] << " ";
    // }

    combination(v, c, m, 0, 0);
    // cout << "cnt : " << cnt << "\n";

    return 0;
}