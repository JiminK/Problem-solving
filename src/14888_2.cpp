#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;
int operators[4]; // +, -, *, / 
long long maxResult = -1000000001, minResult = 1000000001;

int dfs(int idx, int result, int a, int s, int m, int d) {
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

    if (a == 0 &&  s == 0 && m == 0 && d == 0) {
        maxResult = result < maxResult ? maxResult : result;
        maxResult = max(result, maxResult);
        minResult = min(result, minResult);
    }

}


int main() {
    int n; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    for (int i = 0; i < 4; ++i)
        cin >> operators[i];

    

    return 0;
}