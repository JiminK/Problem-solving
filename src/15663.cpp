#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> num, v;
bool check[9];

void dfs(int idx, int cnt) {
    if (cnt > M) {
        for (int i=0; i<v.size(); ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    
    for (int i=idx; i<num.size(); ++i) {
        if (check[i]) continue;
        check[i] = true;
        if (v.back() == num[i]) continue;
        v.push_back(num[i]);
        dfs(i, cnt+1);
        v.pop_back();
    }
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        num.push_back(temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    sort(num.begin(), num.end());
    v.push_back(num[0]); check[0] = true;
    dfs(0, 2);

    return 0;
}