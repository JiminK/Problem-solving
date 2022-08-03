#include <iostream>
#include <deque>

using namespace std;

int N;
struct strt {
    int idx;
    int paperNum;
};
deque<strt> balloon;

void solve() {
    while (!balloon.empty()) {
        int nowIdx = balloon.front().idx;
        int nextIdx = balloon.front().paperNum;
        balloon.pop_front();
        cout << nowIdx << " ";
        if (nextIdx < 0) {
            while (nextIdx != 0) {
                balloon.push_front(balloon.back());
                balloon.pop_back();
                nextIdx += 1;
            }
        }
        if (nextIdx > 0) {
            nextIdx -= 1;
            while (nextIdx != 0) {
                balloon.push_back(balloon.front());
                balloon.pop_front();
                nextIdx -= 1;
            }
        }
    }

    // int now = balloon[0].idx - 1;
    // int next = balloon[0].paperNum;
    // balloon[0].paperNum = 0;
    // cout << now << " ";
    // if (next < 0) {
    //     next = N - 1;
    // }
    // if (next > N - 1) {
    //     next = 0;
    // }

    // next = balloon[now].paperNum;
    // balloon[now] = 0;

    // for (int i=0; i<N-1; ++i) {
    //     now = next;
    //     next += balloon[now];
    //      if (next < 0) {
    //             next = N - 1;
    //     }
    //     if (next > N - 1) {
    //         next = 0;
    //     }
    //     while (balloon[next] == 0) {
    //         if (next < 0) {
    //             next -= 1;
    //         }
    //         if (next > 0) {
    //             next += 1;
    //         }
    //     }
    //     cout << next + 1 << " ";
    //     balloon[now] = 0;
    // }
    // cout << "\n";
}

void getInput() {
    cin >> N;
    for (int i=1; i<=N; ++i) {
        strt temp;
        temp.idx = i;
        cin >> temp.paperNum;
        balloon.push_back(temp);
    }
    solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << "\n";

    return 0;
}

// https://luv-n-interest.tistory.com/1305 