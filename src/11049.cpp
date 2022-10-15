#include <iostream>
#include <vector>

#define MAX_N 500

using namespace std;

int N;
long long cnt;
int matrix[MAX_N + 1][2];

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        int r, c; cin >> r >> c;
        matrix[i][0] = r;
        matrix[i][1] = c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}