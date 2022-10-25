#include <iostream>
#include <string>

using namespace std; 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

	int n; cin >> n;
	int DP[50][2];
 
  // 1번 눌렀을 때, A -> B
	DP[1][0] = 0; // A의 개수
	DP[1][1] = 1; // B의 개수
  // 2번 눌렀을 때, B -> BA
	DP[2][0] = 1; 
	DP[2][1] = 1; 
 
	for (int i=3; i<=n; ++i) {
		DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
		DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
	}
 
	cout << DP[n][0] << " " << DP[n][1] << "\n";
 
	return 0;
}