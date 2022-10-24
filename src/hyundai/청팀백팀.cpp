#include <iostream>
#include <vector>
#include <queue>

#define MAXA 1000000

using namespace std;

int M, N;
int startNum;
vector<int> vec[MAXA+1];

struct strt {
  int a;
  int team;
};
queue<strt> q;

int team[MAXA+1];
bool check[MAXA+1];
int teamFlag = 1;

bool bfs() {
  q.push({startNum, teamFlag});
  team[startNum] = teamFlag;
  check[startNum] = true;

  while (!q.empty()) {
    // for (int i=1; i<=M; ++i) {
    //   cout << team[i] << ", ";
    // }cout <<"\n";
    strt curr = q.front(); q.pop();
    for (int i=0; i<vec[curr.a].size(); ++i) {
      int next = vec[curr.a][i];
      if (curr.team == team[next]) {
        // cout << "curr " << curr.a << ", next " << next << "\n";
        return false;
      }
      if (check[next]) continue;
      q.push({next, -curr.team});
      team[next] = -curr.team;
      check[next] = true;
    }
  }
  return true;
}

void solve() {
  bool ans = bfs();
  if (ans == false) cout << 0 << "\n";
  else cout << 1 << "\n";  

}

void getInput() {
  cin >> M >> N;
  for (int i=0; i<N; ++i) {
    int ai, bi; cin >> ai >> bi;
    vec[ai].push_back(bi);
    vec[bi].push_back(ai);
    startNum = ai;
    cout << startNum << "sfafdfdsewf\n";
  }   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}