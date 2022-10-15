#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// int sum;
int arr[9];
bool chk;

void dfs(int idx, int sum, int cnt, vector<int> who) {
    // cout << idx << ", " << sum << endl;
    if (sum == 100 && cnt == 7 && !chk) {
        sort(who.begin(), who.end());
        for(int i=0; i<7; ++i){
            cout << who[i] << "\n";
        }
        chk = true;
        return;
    }
    if (sum > 100 || idx > 8) {
        // sum -= arr[idx];
        return;
    }

    // 1. 지금 idx 가 난쟁이인 경우
    who.push_back(arr[idx]);
    dfs(idx+1, sum + arr[idx], cnt+1, who);

    // 2. 지금 idx 가 난쟁이가 아닌 경우 
    who.pop_back();
    dfs(idx+1, sum, cnt, who);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=0; i<9; ++i) {
        cin >> arr[i];
    }
    vector<int> v;
    dfs(0, 0, 0, v);

    return 0;
}