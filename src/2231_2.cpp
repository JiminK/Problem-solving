#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for (int i = n; i > 0; --i) {
        int tempN = i;
        int tempNSum = 0;

        while (tempN != 0) {
            int tmp = tempN % 10;
            tempNSum += tmp;
            tempN /= 10;
        }
        
        cout << "tempNSum : " << tempNSum << "\n";
        i += tempNSum;
        cout << "i : " << i << "\n";

    }


    return 0;
}