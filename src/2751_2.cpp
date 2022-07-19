#include <iostream>
#include <algorithm>

#define MAX_N 10000000

using namespace std;

int N;
int arr[MAX_N + 1];

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    sort(arr, arr + N);
    for (int i=0; i<N; ++i) {
        cout << arr[i] << "\n";
    }

    return 0;
}