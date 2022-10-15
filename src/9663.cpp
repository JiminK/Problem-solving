#include <iostream>

using namespace std;

int N;
int chess[15];
int cnt;

bool verify(int d) {
  for (int i=1; i<=d; ++i) {
    if (chess[d] == chess[j] || d-chess[j] == chess[d]-chess[j] || d-chess[j] == chess[j]-chess[d])
    return false;
  }

  return true;
}

void dfs(int depth) {
  // 종료조건
  if (depth == N+1) {
    cnt++;
    return;
  }

  for (int j=1; j<=depth; ++j) {
    if (verify(depth)) {
      chess[depth] = j;
      dfs(depth+1);

    }
  }
}

void solve() {
  chess[1] = 1;
  dfs(1);
  cout << cnt << "\n";
}

void getInput() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}