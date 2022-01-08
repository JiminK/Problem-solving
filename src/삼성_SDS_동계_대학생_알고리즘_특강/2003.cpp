#include <iostream>
using namespace std;

#define MAX_N 10001
int arr[MAX_N];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int N, M; 
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = 0;
    for (int i = 0; i < N; ++i) {
        int sum = arr[i];
        if (sum == M) { 
            result += 1;
            continue;
        }
        for (int j = i + 1; j < N; ++j) {
            sum += arr[j];
            if (sum == M)
                result += 1;
            if (sum > M)
                break;
        }
    }
    cout << result << "\n";
    return 0;
}