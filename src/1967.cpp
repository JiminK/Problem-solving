#include <iostream>
#include <vector>

#define MAXN 10000

using namespace std;

int N;
vector<pair<int, int>> T[MAXN+10];
bool check[MAXN+10];
int maxi;
int node;

void dfs(int idx, int weight) {
    if (check[idx]) return;
    check[idx] = true;

    if (weight >= maxi) {
        maxi = weight;
        node = idx;
    }
    for (int i=0; i<T[idx].size(); ++i) {
        dfs(T[idx][i].first, weight + T[idx][i].second);
    }
    // sum += T[idx][node].second;
}

void init() {
    for (int i=0; i<MAXN+10; ++i)
        check[i] = false;
    maxi = 0;
}

void solve() {
    // 1. 루트노드에서 가장 멀리 떨어진 정점 찾기
    dfs(1, 0);
    
    // 2. 찾은 정점에서 가장 멀리 떨어진 정점 찾기
    init();
    dfs(node, 0);
    cout << maxi << "\n";
}

void getInput() {
    cin >> N;
    for (int i=0; i<N-1; ++i) {
        int u, v, w; cin >> u >> v >> w; 
        T[u].push_back({v, w});
        T[v].push_back({u, w});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}