#include <iostream>
#include <string>
using namespace std;

// int countDigits(long long n) {
//     string str;
//     str = to_string(n);
//     return str.length();
// }

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        long long num; cin >> num;
        string ans = to_string(num);

        // int numLen = countDigits(num);
        // int ansLen = numLen;

        for (int i = ans.length() - 1; i > 0; --i) {
            if (ans[i - 1] >= ans[i]) {
                continue;
            } else { // else if (ans[i - 1] < ans[i])  
                
            } 

        }

        cout << "BIGGEST" << "\n";
    }

    return 0;
}