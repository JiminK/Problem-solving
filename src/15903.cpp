#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<long long> v;
    for (int i = 0; i < n; ++i) {
        long long temp; cin >> temp;
        v.push_back(temp);
    }
    
    // 4 2
    // 4 2 3 1  =>  4 5 6 7 
    while (m != 0) {
        sort(v.begin(), v.end());
        long long sum = v[0] + v[1];
        v[0] = sum;
        v[1] = sum;
        // 9 9 6 7 => 6 7 9 9 => 13 13 9 9 ==> 26+18 = 44
        m--;
    }
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        result += v[i];
    }
    cout << result << "\n";

    return 0;
}