#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;
vector<int> vec2;

void solve() {
    // 중복 제거 
    vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
    
    for (int i=0; i<N; ++i) {
        cout << lower_bound(vec2.begin(), vec2.end(), vec[i]) - vec2.begin() << " ";
    }
    cout << "\n";
} 

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        vec.push_back(temp);
        vec2.push_back(temp);
    }
    // sort(vec.begin(), vec.end());
    sort(vec2.begin(), vec2.end());
    solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}

// https://chanhuiseok.github.io/posts/algo-55/ : 참고 링크 
// https://programmers.co.kr/learn/courses/30/lessons/60060 : 카카오 기출 문제 
// https://chanhuiseok.github.io/posts/algo-55/ : lower_bound 