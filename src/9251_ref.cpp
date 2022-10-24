#include <iostream>
#include <string>

using namespace std;

string word1, word2;
int w1, w2, DP[1001][1001];

void solve() {
    for (int i=1; i<=word1.size(); ++i) {
        for (int j=1; j<=word2.size(); ++j) {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (word1[i-1] == word2[j-1]) 
                DP[i][j] = DP[i-1][j-1] + 1;
            else 
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }
    cout << DP[w1][w2];
}

void getInput() {
    cin >> word1 >> word2;
    w1 = word1.size(), w2 = word2.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}