#include <iostream>
#include <string>
using namespace std;

int countDigits(long long n) {
    string str;
    str = to_string(n);
    return str.length();
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        long long num; cin >> num;
        long long ans = num;
        int numLen = countDigits(num);
        int ansLen = numLen;

        while (ansLen == numLen) {
            
            

            ansLen = countDigits(ans);
            ans++;
        }




    }

    return 0;
}