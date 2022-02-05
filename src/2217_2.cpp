#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_NUM 100000 + 1

int arr[MAX_NUM];

bool desc(int a, int b){ 
  return a > b; 
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n, desc);
    
    int maxW = 0;
    int nowW = -1;
    for (int i = 0; i < n; ++i) {
        // nowW = arr[n - i - 1] * (i + 1);
        nowW = arr[i] * (i + 1);
        // cout << "nowW : " << nowW << "\n";
        // cout << "maxW : " << maxW << "\n";
        if (maxW < nowW)
            maxW = nowW;
        // cout << "after maxW : " << maxW << "\n";
    }
    cout << maxW << "\n";
    return 0;
}