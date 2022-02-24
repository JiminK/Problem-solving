#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;
int operators[4]; 
int maxResult = -1000000001, minResult = 1000000001;

void dfs(int idx, int result, int a, int s, int m, int d) {
    if (a > 0) {
        // cout << "+" << "\n";
        // cout << "result : " << result << "\n";
        dfs(idx + 1, result + numbers[idx + 1], a - 1, s, m, d);
    }
    if (s > 0) {
        dfs(idx + 1, result - numbers[idx + 1], a, s - 1, m, d);
    }
    if (m > 0) {
        // cout << "*" << "\n";
        // cout << "numbers : " << numbers[idx] << ", " << numbers[idx + 1] << "\n";
        dfs(idx + 1, result * numbers[idx + 1], a, s, m - 1, d);
    }
    if (d > 0) {
        dfs(idx + 1, result / numbers[idx + 1], a, s, m, d - 1);
    }

    if (a == 0 && s == 0 && m == 0 && d == 0) {
        maxResult = max(result, maxResult);
        minResult = min(result, minResult);
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    for (int i = 0; i < 4; ++i)
        cin >> operators[i];

    dfs(0, numbers[0], operators[0], operators[1], operators[2], operators[3]);
    cout << maxResult << "\n" << minResult << "\n";

    return 0;
}