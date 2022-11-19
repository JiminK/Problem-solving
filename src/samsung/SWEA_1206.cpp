#include <iostream>

#define MAXN 1000

using namespace std;

int N;
int buildings[MAXN+10];
int ansArr[MAXN+1];
int ans;

void init() {
  ans = 0;
  
}

void addAns() {
  for (int i=0; i<N; ++i) {
    ans += ansArr[i];
  }
}

void solve() {
  for (int i=2; i<N-2; ++i) {
    int mini = 256;
    int curr = buildings[i];

    for (int j=-2; j<3; ++j) {
      if (j == 0) continue;
      int next = buildings[i+j];
      if (curr-next < 0) {
        ansArr[i] = 0;
        break;
      }
      if (curr-next < mini) {
        mini = curr-next;
        ansArr[i] = mini;
      }
    }
  }
}

void getInput() {
  for (int i=0; i<10; ++i) { // T = 10
    init();
    cin >> N;
    for (int j=0; j<N; ++j) {
      int height; cin >> height;
      buildings[j] = height;
    }
    solve();
    addAns();
    cout << "#" << i+1 << " " << ans << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  getInput();

  return 0;
}