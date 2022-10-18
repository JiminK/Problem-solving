
#include <iostream>
#include <algorithm>
#include <string>
#define MAXN 20
using namespace std;

int R, C, arr[MAXN][MAXN];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool check[26];
int dfs(int x, int y)
{
  int ret = 0;
  for (int j = 0; j < 4; ++j)
  {
    int nx = x + dir[j][0];
    int ny = y + dir[j][1];
    if (nx < 0 || nx >= C || ny < 0 || ny >= R || check[arr[ny][nx]])
      continue;
    check[arr[ny][nx]] = true;
    ret = max(ret, dfs(nx, ny));
    check[arr[ny][nx]] = false;
  }
  return ret + 1;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C;
  for (int y = 0; y < R; ++y)
  {
    string str;
    cin >> str;
    for (int x = 0; x < C; ++x)
      arr[y][x] = str[x] - 'A';
  }
  check[arr[0][0]] = true;
  cout << dfs(0, 0) << "\n";
  return 0;
}