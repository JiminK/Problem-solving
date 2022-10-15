#include <iostream>
#include <queue>

#define MAXN 50
#define MAXM 10

using namespace std;

int N, M;
int LAB[MAXN+1][MAXN+1];
struct strt {
    int r, c;
    int time;
    int zeros;
};
vector<strt> virus;
vector<vector<strt>> selected;
bool check[MAXN+1][MAXN+1];
queue<strt> q;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int zeroCnt;
int minTime = 999999;

int __bfs(vector<strt> v) {
    while (!v.empty()) {
        q.push(v.front()); q.pop();
    }

    while (!q.empty()) {
        int currR = q.front().r, currC = q.front().c;
        int currT = q.front().time;
        int currZ = q.front().zeros;
        q.pop();
        check[currR][currC] = true;

        if (currZ == zeroCnt) {
            minTime = min(minTime, currT);
            return minTime;
        }
        for (int i=0; i<4; ++i) {
            int nextR = currR + dir[i][0], nextC = currC + dir[i][1];

            // 바운드 체크
            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) continue;

            // 이미 방문했으면 컨티뉴
            if (check[nextR][nextC]) continue;

            // 벽 만나면 컨티뉴
            if (LAB[nextR][nextC] == 1) continue;

            // 빈칸일 때, 그냥 이동
            if (LAB[nextR][nextC] == 0) { 
                q.push({nextR, nextC, currT+1, currZ+1});
                check[nextR][nextC] = true;
                continue;
            }

            // 바이러스일 때, 활성화 안 하고 이동
            if (LAB[nextR][nextC] == 2) { 
                check[nextR][nextC] = true;
                continue;
            }
        }
    }
    if (minTime != 999999) return minTime;
    return minTime = -1;
}

// int _bfs(queue<strt> _q){
//     while(!_q.empty()){
//         q.push(_q.front()); _q.pop();
//     }
//     while(!q.empty()) {
//         int currR = q.front().r, currC = q.front().c;
//         int currT = q.front().time;
//         int currZ = q.front().zeros;
//         q.pop();
//         check[currR][currC] = true;

//         if (currZ == zeroCnt) {
//             minTime = min(minTime, currT);
//             return minTime;
//         }
//         for (int i=0; i<4; ++i) {
//             int nextR = currR + dir[i][0], nextC = currC + dir[i][1];

//             // 바운드 체크
//             if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) continue;

//             // 이미 방문했으면 컨티뉴
//             if (check[nextR][nextC]) continue;

//             // 벽 만나면 컨티뉴
//             if (LAB[nextR][nextC] == 1) continue;

//             // 빈칸일 때, 그냥 이동
//             if (LAB[nextR][nextC] == 0) { 
//                 q.push({nextR, nextC, currT+1, currZ+1});
//                 check[nextR][nextC] = true;
//                 continue;
//             }

//             // 바이러스일 때, 활성화 안 하고 이동
//             if (LAB[nextR][nextC] == 2) { 
//                 check[nextR][nextC] = true;
//                 continue;
//             }
//         }
//     }
//     if (minTime != 999999) return minTime;
//     return minTime = -1;
// }

// int bfs(int r, int c) {
//     q.push({r, c, 0, 0});
//     check[r][c] = true;
//     while (!q.empty()) {
//         int currR = q.front().r, currC = q.front().c;
//         int currT = q.front().time;
//         int currZ = q.front().zeros;
//         q.pop();

//         if (currZ == zeroCnt) {
//             minTime = min(minTime, currT);
//             return minTime;
//         }
//         for (int i=0; i<4; ++i) {
//             int nextR = currR + dir[i][0], nextC = currC + dir[i][1];

//             // 바운드 체크
//             if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) continue;

//             // 이미 방문했으면 컨티뉴
//             if (check[nextR][nextC]) continue;

//             // 벽 만나면 컨티뉴
//             if (LAB[nextR][nextC] == 1) continue;

//             // 빈칸일 때, 그냥 이동
//             if (LAB[nextR][nextC] == 0) { 
//                 q.push({nextR, nextC, currT+1, currZ+1});
//                 check[nextR][nextC] = true;
//             }

//             // 바이러스일 때, 활성화 안 하고 이동
//             if (LAB[nextR][nextC] == 2 && currCnt >= M) { 
//                 check[nextR][nextC] = true;
//                 continue;
//             }

//             // 바이러스일 때, 활성화 시키고 이동
//             if (LAB[nextR][nextC] == 2 && currCnt < M) { 
//                 q.push({nextR, nextC, currT+1, currZ+1});
//                 check[nextR][nextC] = true;
//             }
            
//         }
//     }
//     if (minTime != 999999) return minTime;
//     return minTime = -1;    
// }

// void combi(int idx, int r, int depth) { // dfs
//     if (r == 0) {
//         queue<strt> _q;
//         for(int i=0; i<M; ++i){
//             strt temp = {selected[i].r, selected[i].c, 0, 0};
//             _q.push(temp);
//         }
//         _bfs(_q);
//         // bfs(selected[idx].r, selected[idx].c);
//         // minTime = min(minTime, mini);
//     } else if (depth == virus.size()) return;
//     else {
//         selected[idx].r = virus[depth].r;
//         selected[idx].c = virus[depth].c;
//         // 선택 o
//         combi(idx+1, r-1, depth+1);
//         // 선택 x
//         combi(idx, r, depth+1);
//     }
// }

void combi(vector<strt> c, int r, int depth) {
    if (r == 0) {
        selected.push_back(c);
    } else if (depth >= virus.size()) return;
    else {
        c.push_back({virus[depth].r, virus[depth].c, 0, 0});
        combi(c, r-1, depth+1);
        c.pop_back();
        combi(c, r, depth+1);
    }
}

void solve() {
    vector<strt> v(0);
    combi(v, M, 0);
    
    for (int i=0; i<selected.size(); ++i) {
        __bfs(selected[i]);
    }

    // int r = 0;
    // for (int i=0; i<N; ++i) {
    //     for (int j=0; j<N; ++j) {
    //         if (LAB[i][j] == 0 && check[i][j] == false) {
    //             minTime = -1;
    //             return;
    //         }
    //     }
    // }

    cout << minTime << "\n";
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            int temp; cin >> temp;
            LAB[i][j] = temp;
            if (temp == 2) virus.push_back({i, j});
            else if (temp == 0) zeroCnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}