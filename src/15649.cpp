#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
bool check[9];

void dfs(int cnt) {
    if (cnt > M) {
        for (int i=0; i<M; ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for (int i=1; i<=N; ++i) {
        if (check[i] == true) continue;
        check[i] = true;
        v.push_back(i);
        dfs(cnt+1);
        v.pop_back();
        check[i] = false;
    }
}

void getInput() {
    cin >> N >> M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    dfs(1);
    
    return 0;
}