#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
struct strt {
    int idx;
    int xi;
    int newXi;

    bool operator > (const strt &s) const {
        return xi > s.xi;
    }
    bool operator < (const strt &s) const {
        return xi < s.xi;
    }
};
vector<strt> vec;

bool comp(strt &a, strt &b) {
    return a.idx < b.idx;
}

void solve() {
    vec[0].newXi = 0;
    int temp = vec[0].xi;
    for (int i=1; i<N; ++i) {
        vec[i].newXi = i;
        if (vec[i].xi == temp) {
            vec[i].newXi = vec[i-1].newXi;
        }
        temp = vec[i].xi;
    }
}

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        strt temp; temp.idx = i; cin >> temp.xi;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    solve();
    // for (int i=0; i<N; ++i) {
    //     cout << vec[i].idx << " " << vec[i].xi << " " << vec[i].newXi << "\n";
    // }
    sort(vec.begin(), vec.end(), comp);
    for (int i=0; i<N; ++i) {
        cout << vec[i].idx << " " << vec[i].xi << " " << vec[i].newXi << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}

// https://chanhuiseok.github.io/posts/algo-55/ : 참고 링크 
// https://programmers.co.kr/learn/courses/30/lessons/60060 : 카카오 기출 문제 