#include <iostream>
#include <vector>

#define MAXN 50000

using namespace std;

int N, M, parent[MAXN + 1], depth[MAXN + 1];
vector<int> child[MAXN + 1], G[MAXN + 1];

void build_tree(int v, int par, int dep) { // v: 현재 방문하는 정점, par: v의 부모
    parent[v] = par; // 부모 업데이트
    depth[v] = dep;
    for (int i=0; i<G[v].size(); ++i) {
        int u = G[v][i];
        if (u == par) continue;
        child[v].push_back(u); // 자식 업데이트
        build_tree(u, v, dep+1); // u의 부모는 v
    } // 방문체크 없이도 모든 정점을 한번씩 방문한다. (왜? tree이기 때문)
}
int LCA(int v, int u) {
    if (depth[v] < depth[u]) { // 난 무조건 v를 올려주고 싶다 -> v의 depth가 더 작으면 u랑 swap
        int t = v;
        v = u;
        u = t;
    }
    // ### 방법 1 ### 
    // for (int iv = v, iu = u; depth[iv] != depth[iu];) // index를 pointer로 사용
    // ### 방법 2 ### 
    // while (depth[v] != depth[u])
    //     v = par[v];
    // ### 방법 3 ### 
    for (; depth[v] != depth[u]; v = parent[v])
        ;
    while(v != u) {
        v = parent[v];
        u = parent[u];
    }
    return v; // v랑 u가 같을 때 리턴할 거니까 v, u 둘 중 아무거나 리턴
}  

void getInput() {
    cin >> N;
    for (int i=0; i<N-1; ++i) {
        int v, u;
        cin >> v >> u;
        // 누가 부모인지 자식인지 모름 -> 일단 방향이 없는 그래프로 저장
        G[v].push_back(u);
        G[u].push_back(v);
    }
    
    // 트리 탐색 -> dfs가 가장 편함
    build_tree(1, -1, 0); // parent 없으면 -1로.

    cin >> M;
    for (int i=0; i<M; ++i) {
        int v, u;
        cin >> v >> u;
        cout << LCA(v, u) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    
    return 0;
}