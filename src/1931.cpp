#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans = 1;
struct strt {
    int st, et;
};
vector<strt> vec;

bool cmp(const strt& s1, const strt& s2) {
    if (s1.et == s2.et) return s1.st < s2.st;
    else return s1.et < s2.et;
}

void solve() {
     sort(vec.begin(), vec.end(), cmp);

    int endTime = vec[0].et;
    for (int i=1; i<vec.size(); ++i) {
        if (endTime <= vec[i].st) { 
            endTime = vec[i].et; 
            ans++;
        }
    }
}

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        int a, b; cin >> a >> b;
        vec.push_back({a, b});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    cout << ans << "\n";

    return 0;
}