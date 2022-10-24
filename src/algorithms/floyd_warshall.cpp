#include <iostream>

using namespace std;

bool solve() {
  int INF = 1000000;

  int a[4][4] = {
    { 0, 5, INF, 8 },
    { 7, 0, 9, INF },
    { 2, INF, 0, 4 },
    { INF, INF, 3, 0 }
  };

  // 시간복잡도 V^3
  for(int k = 0; k < 4; k++)  // k 는 거쳐가는 정점
    for(int i = 0; i < 4; i++)  // i 는 행 (출발 정점)
      for(int j = 0; j < 4; j++)  // j 는 열 (도착 정점)
        if (a[i][k] + a[k][j] < a[i][j])  // 점화식 distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
          a[i][j] = a[i][k] + a[k][j];
}

void getInput() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}