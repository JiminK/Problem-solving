#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct strt {
    int v;
    int weight; // u에서 v로 가는 가중치 
    int cost;   // v 노드까지 가는데까지 걸리는 총 거리 

    bool operator < (const strt& st) const {
        return st.cost < cost;
    }
};
int V, E, K;
vector<strt> G[20001];
priority_queue<strt> pq;
unsigned long long ans[20001];
bool check[20001];

void init() {
    for (int i=0; i<=V; ++i) {
        ans[i] = -1;
        // ans[i] = -1;
    }
}

void solve() {
    // for (int i=0; i<G[K].size(); ++i) {
    //     pq.push(G[K][i]);
    // }
    // while (!pq.empty()) {
    //     strt curr = pq.top(); pq.pop();
    // }
    pq.push({K, 0, 0});
    // check[K] = true;
    while(!pq.empty()){
        strt curr = pq.top(); pq.pop();
        if (check[curr.v]) continue;
        check[curr.v] = true;
        for (int i=0; i<G[curr.v].size(); ++i) {
            strt next = G[curr.v][i];
            if (check[next.v]) continue;
            pq.push({next.v, next.weight, next.weight + curr.cost});
            // check[next.v] = true;
        }
        ans[curr.v] = min(ans[curr.v], (unsigned long long)(curr.cost));
        // ans[curr.v] = curr.cost;
    }

    for (int i=1; i<=V; ++i) {
        unsigned long long temp = -1;
        if (ans[i] >= temp) cout << "INF" << "\n";
        else {
            cout << ans[i] << "\n";
        } 
    }
}

void getInput() {
    cin >> V >> E >> K;
    for (int i=0; i<E; ++i) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    init();
    solve();

    return 0;
}