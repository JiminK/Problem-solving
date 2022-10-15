#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAXV 10000
#define MAXE 100000

using namespace std;

int V, E;
struct strt {
    int v, cost;
};
// djset => 크루스칼
int djset[MAXV], djset_cnt[MAXV]; // 배열의 크기는 간선의 개수만큼! -> 근데 정점크기로 해야됨..?
void djset_init() {
    for (int i=0; i<MAXE; ++i) {
        djset[i] = i;
        djset_cnt[i] = 1;
    }
}
int djset_find(int v) {
    if (djset[v] == v) return v; // 자기자신을 참조하면 종료
    // 부모 찾아가기 
    int r = djset_find(djset[v]); 
    djset[v] = r; // 경로압축
    return r;
}
void djset_union(int v1, int v2) {
    int r1 = djset_find(v1);
    int r2 = djset_find(v2);
    if (r1 == r2) return;
    if (djset_cnt[r1] < djset_cnt[r2]) {
        djset[r1] = r2;
        djset_cnt[r2] += djset_cnt[r1];
    } else {
        djset[r2] = r1;
        djset_cnt[r1] += djset_cnt[r2];
    }
}

vector<strt> G[MAXV];                    // 프림
vector<pair<int, pair<int, int>>> edges; // 크루스칼

int kruskal() {
    int ans = 0;

    djset_init();
    
    sort(edges.begin(), edges.end());
    
    for (int i=0, c=0; i<edges.size() && c < V-1; ++i) {
        int cost = edges[i].first;
        int v = edges[i].second.first;
        int u = edges[i].second.first;

        if (djset_find(v) != djset_find(u)) {  // 연결되어 있지 않으면 합치기 
            djset_union(v, u);
            ans += cost;
            ++c;
        }
    }
    return ans;
}

int prim() {
    int ans = 0;

    vector<bool> check(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    check[0] = true;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (check[v]) continue;
        check[v] = true; // 뽑혔을 때 최소라는 거니까, 그때 방문체크
        ans += cost;

        for (int i=0; i<G[v].size(); ++i) { // 인접리스트 탐색
            int u = G[v][i].v;
            int c = G[v][i].cost;

            if (check[u]) continue;
            pq.push({c, u});
        } 
    }
    return ans;
}

void getInput() {
    cin >> V >> E;
    for (int i=0; i<E; ++i) {
        int v, u, cost;
        cin >> v >> u >> cost;
        G[v-1].push_back({u-1, cost}); // index가 문제는 1부터인데 우리는 0부터라서 -1 해줘야 한다.
        G[u-1].push_back({v-1, cost});

        edges.push_back({cost, {v-1, u-1}});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << prim() << "\n";

    return 0;
}