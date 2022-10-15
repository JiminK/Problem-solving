#include <iostream>

#define MAX_N 26

using namespace std;

int N;
struct strt {
  int left, right;
};
strt BT[MAX_N + 1];

void preorder(char c) {
  if (c == '.') return;
  cout << c;
  preorder(BT[c - 'A'].left);
  preorder(BT[c - 'A'].right);
}

void inorder(char c) {
  if (c == '.') return;
  inorder(BT[c - 'A'].left);
  cout << c;
  inorder(BT[c - 'A'].right);
}

void postorder(char c) {
  if (c == '.') return;
  postorder(BT[c - 'A'].left);
  postorder(BT[c - 'A'].right);
  cout << c;
}

void solve() {
  preorder('A');
  cout << "\n";
  inorder('A');
  cout << "\n";
  postorder('A');
}

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
      char root, left, right; cin >> root >> left >> right;
        BT[root - 'A'].left = left; BT[root - 'A'].right = right;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}