#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100
#define MAXW 100000

using namespace std;

int N, K, W, V;
struct strt {
    int w, v;
};
vector<strt> products;
int DP[MAXN+1][MAXW+1];

void solve() { 
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=K; ++j) {
            if (products[i].w <= j) {
                DP[i][j] = max(DP[i-1][j-products[i].w] + products[i].v, DP[i-1][j]);
            }
            else { // products[i].w > j
                DP[i][j] = DP[i-1][j];
            }

        }
    }
    cout << DP[N][K] << "\n";
}

void getInput() {
    cin >> N >> K;
    products.push_back({0, 0});
    for (int i=1; i<=N; ++i) {
        cin >> W >> V;
        products.push_back({W, V});
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}