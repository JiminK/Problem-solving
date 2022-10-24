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

  for(int k = 0; k < 4; k++) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++)  {
        if (a[i][k] + a[k][j] < a[i][j]){
          a[i][j] = a[i][k] + a[k][j];
        }
      }
    }
    // 음의 사이클을 찾으려면 이중 for loop을 한번 더 돌려본다!
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++)  {
        // 또 최솟값이 갱신되면 -> 음의 사이클이 존재한다는 뜻!
        if (a[i][k] + a[k][j] < a[i][j]){
          return false;
        }
      }
    }
  }
  return true;          
}
void getInput() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}