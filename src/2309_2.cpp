#include <iostream>
#include <algorithm>

using namespace std;

int sum;
int arr[9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=0; i<9; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+9);

    int r = 0, c = 0;
    // 가짜 난쟁이 2명을 위한 2중 for loop 
    for (r=0; r<9; ++r) {
        for (c=1; c<9; ++c) {
            // (9명 전체 키의 합) - (가짜 난쟁이 2명의 키) == 100 
            if (sum - (arr[r] + arr[c]) == 100) {
                for (int i=0; i<9; ++i) {
                    if (i != r && i != c)
                        cout << arr[i] << "\n";
                }
                return 0;
            }
        }
    }

    // for (int i=0; i<9; ++i) {
    //     if (i != r || i != c)
    //         cout << arr[i] << "\n";
    // }

    return 0;
}