#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> subject[1001];
int cnt[1001];
int ans[1001];
struct strt {
    int sub;
    int semester;
};
queue<strt> q;

void bfs() {
    while (!q.empty()) {
        int currSub = q.front().sub, currSem = q.front().semester; 
        q.pop();
        // cout << currSub << ", " << currSem << "\n";
        // for (int i=0; i<N; ++i) cout << cnt[i+1] << ", ";
        // cout << "\n";
        
        for (int i=1; i<=N; ++i) {
            for (int j=0; j<subject[i].size(); ++j) {
                if (subject[i][j] == currSub) {
                    cnt[i]--;
                    // 선수과목의 수가 0이 되면 queue에 push, ans배열에 저장
                    if (cnt[i] == 0) {
                        q.push({i, currSem+1});
                        ans[i] = currSem+1;
                    }
                }
            }
        }
    }
}

void solve() {
    for (int i=1; i<=N; ++i) {
        if (subject[i].empty()) {
            q.push({i, 1});
            ans[i] = 1;
        }
        else {
            cnt[i] = subject[i].size();
        }
    }

    bfs();

    for (int i=1; i<=N; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        int A, B; cin >> A >> B;
        subject[B].push_back(A);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}