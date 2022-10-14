#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

void dfs(vector<int> c, int r, int depth, int idx) {
    if (r == 0) {
        for (int i=0; i<c.size(); ++i)
            cout << c[i] << " ";
        cout << "\n";
    }
    else if (depth == v.size()) return;
    else {
        c[idx] = v[depth];
        // 선택 o
        dfs(c, r-1, depth+1, idx+1);
        // 선택 x
        dfs(c, r, depth+1, idx);
    }
    
}

void getInput() {
   cin >> N >> M;
   for (int i=0; i<N; ++i) {
       int temp; cin >> temp;
       v.push_back(temp);
   }
   sort(v.begin(), v.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    vector<int> c(M);
    dfs(c, M, 0, 0);

    return 0;
}