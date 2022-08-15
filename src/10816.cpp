#include <iostream>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<int, int> um;

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        int card; cin >> card;
        um[card]++;
    }
    cin >> M;
    for (int i=0; i<M; ++i) {
        int card; cin >> card;
        cout << um[card] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}