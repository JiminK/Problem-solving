#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    long abc = a * b * c;

    int arr[10] = {0};

    while (abc != 0) {
        int tmp = abc % 10;
        arr[tmp]++;
        abc /= 10;
    }

    for (int i = 0; i < 10; ++i) 
        cout << arr[i] << "\n";

    return 0;
}