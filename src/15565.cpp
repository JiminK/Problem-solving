#include <iostream>
#include <vector>

#define MAX_N 1000000

using namespace std;

int N, K, idx;
int answer = -1;
int minAnswer = MAX_N + 5;
vector<int> isRyan;

void getDiff() {
    if (isRyan.size() < K) {
        minAnswer = -1;
        return;
    }
    for (int i=0; i<=isRyan.size()-K; ++i) {
        int diff = isRyan[i+K-1] - isRyan[i] + 1;
        if (diff < minAnswer) minAnswer = diff;
        // cout << minAnswer << "=====\n";
    }
    if (minAnswer == 1000005) minAnswer = -1;
}

void getInput() {
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        // 라이언(1) index 저장 
        if (temp == 1) {
            isRyan.push_back(i);
        }
    }
    getDiff();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << minAnswer << "\n";

    return 0;
}