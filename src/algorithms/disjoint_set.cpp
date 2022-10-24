#include <iostream>

#define MAXN 1000

using namespace std;

int root[MAXN], cnt[MAXN];

int find(int v) {
  if (root[v] == v) return v;
  int r = find(root[v]);
  // 좌표압축
  root[v] = r;
  return r;
}

void union_(int v, int u) {
  int vRoot = find(v);
  int uRoot = find(u);
  // v와 u의 루트가 같다 = 이미 같은 집합이다
  if (vRoot == uRoot) return;
  // 루트가 다르면, 원소의 개수가 더 많은 집합의 루트의 자식으로 합친다. 
  if (cnt[vRoot] < cnt[uRoot]) {
    root[vRoot] = uRoot;
    cnt[uRoot] += cnt[vRoot];
  } else { // cnt[vRoot] >= cnt[uRoot]
    root[uRoot] = vRoot;
    cnt[vRoot] += cnt[uRoot];
  }
}

int main() {
  for (int i=0; i<MAXN; ++i) {
    root[i] = i;
    cnt[i] = 1;
  }
  return 0;
}