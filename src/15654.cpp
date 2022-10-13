#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> num, v;
bool check[10001];

void dfs(int idx, int cnt) {
    if (cnt > M) {
        for (int i=0; i<v.size(); ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    
    for (int i=0; i<num.size(); ++i) {
        if (check[num[i]]) continue;
        check[num[i]] = true;
        v.push_back(num[i]);
        dfs(num[i], cnt+1);
        v.pop_back();
        check[num[i]] = false;
    }
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    dfs(num[0], 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}