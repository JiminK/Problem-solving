#include <iostream>
#include <map>

using namespace std;

int T, N;
map<string, int> clothes;

void solve() {
    int answer = 1;
    for (auto iter = clothes.begin(); iter != clothes.end(); ++iter) {
        answer *= iter->second + 1;
    }
    cout << answer - 1 << "\n";
}

void getInput() {
    cin >> T;
    for (int i=0; i<T; ++i) {
        clothes.clear(); // 초기화!
        cin >> N;
        for (int j=0; j<N; ++j) {
            string name, type; cin >> name >> type;
            clothes[type]++;
        }
        // for (auto iter = clothes.begin(); iter != clothes.end(); ++iter) {
        //     cout << "iter->first: " << iter->first << "\n";
        //     cout << "iter->second: " << iter->second << "\n";
        // }
        solve();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}

// https://www.delftstack.com/ko/howto/cpp/how-to-iterate-over-map-in-cpp/ : 맵 for loop