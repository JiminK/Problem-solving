#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec;

void solve(int left, int right) {
    while (left <= right) {
        // mid : 1개의 블루레이의 크기 
        int mid = (left + right) / 2;
        // sum : 동영상 길이 합, cnt : 블루레이의 개수
        int sum = 0, cnt = 0; 
        for (int i=0; i<vec.size(); ++i) {
            if (sum + vec[i] > mid) {
                ++cnt;
                sum = 0;
            }
            sum += vec[i];
        }
        if (cnt >= M) {
            left = mid + 1;
        }
        else { // else if (cnt < M)
            right = mid - 1;
        }
    }
    cout << left << "\n";
}

void getInput() {
    cin >> N >> M;
    int l = -1, r = 0;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        l = max(l, temp);
        r += temp;
        vec.push_back(temp);
    }
    solve(l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}

// 참고: https://chanhuiseok.github.io/posts/baek-22/ 