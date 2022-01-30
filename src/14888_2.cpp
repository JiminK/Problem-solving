#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;
int operators[4]; // +, -, *, / 
long long maxResult = -1000000001, minResult = 1000000001;

void dfs(int idx, long long result, int a, int s, int m, int d) {
    if (a > 0) {
        result = numbers[idx] + numbers[idx + 1];
        dfs(idx + 1, result, a - 1, s, m, d);
    }
    if (s > 0) {
        result = numbers[idx] - numbers[idx + 1];
        dfs(idx + 1, result, a, s - 1, m, d);
    }
    if (m > 0) {
        result = numbers[idx] * numbers[idx + 1];
        dfs(idx + 1, result, a, s, m - 1, d);
    }
    if (d > 0) {
        result = numbers[idx] / numbers[idx + 1];
        dfs(idx + 1, result, a, s, m, d - 1);
    }

    if (a == 0 && s == 0 && m == 0 && d == 0) {
        maxResult = result < maxResult ? maxResult : result;
        maxResult = max(result, maxResult);
        minResult = min(result, minResult);
        cout << maxResult << "\n" << minResult << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    for (int i = 0; i < 4; ++i)
        cin >> operators[i];

    dfs(0, 0, operators[0], operators[1], operators[2], operators[3]);

    return 0;
}