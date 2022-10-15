#include <iostream>

#define MAXN 1000

using namespace std;

int par[MAXN], cnt[MAXN];

int find(int v) {
  if (par[v] == v) return v;
  int r = find(par[v]);
  // 좌표압축
  par[v] = r;
  return r;
}

void union_(int v, int u) {
  int vr = find(v);
  int ur = find(u);
  if (vr == ur) return;
  if (cnt[vr] < cnt[ur]) {
    par[vr] = ur;
    cnt[ur] += cnt[vr];
  } else { // cnt[vr] >= cnt[ur]
    par[ur] = vr;
    cnt[vr] += cnt[ur];
  }
}

int main() {
  for (int i=0; i<MAXN; ++i) {
    par[i] = i;
    cnt[i] = 1;
  }
  return 0;
}