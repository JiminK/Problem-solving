#include <iostream>
using namespace std;

int find(int N)
{
    int cnt = 0, sum = 0, tmp2 = 0;
    int tmp = N;
    while (tmp > 0) {
        tmp /= 10;
        cnt++;
    }
    int s = N - cnt * 9;
    tmp = s;

    while (true) {
        sum = tmp;
        tmp2 = tmp;
        while (tmp2) {
            sum += tmp2 % 10;
            tmp2 /= 10;
        }
        if (sum == N)
            return tmp;
        else if (tmp == N)
            return 0;
      
        tmp++;
    }
}
int main() {
    int N;
    cin >> N;
    cout << find(N) << endl;
    return 0;
}