#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int N, K, ans = 1;
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        ans *= N - i;
    }
    for (int i = 0; i < K; ++i) {
        ans /= (K - i);
    }
    cout << ans <<"\n";
    return 0;
}