#include <iostream>
#include <vector>

using namespace std;

void combination (vector<int> v, vector<int> c, int r, int idx, int depth) {
    if (r == 0) {
        for (int i = 0; i < c.size(); ++i) {
            cout << c[i] << " ";
        }
        cout << "\n"; 
    } else if (depth == v.size()) {
        return;
    } else {
        c[idx] = v[depth];
        combination(v, c, r - 1, idx + 1, depth + 1);
        combination(v, c, r, idx, depth + 1);
    }
}

int main() {
    int n, m; 
    cin >> n >> m;

    vector<int> v(n), c(m);
    for (int i = 1; i <= n; ++i) {
        v[i - 1] = i;
    }

    combination(v, c, m, 0, 0);

    return 0;
}