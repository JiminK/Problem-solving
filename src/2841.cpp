// TIMEOUT
#include <iostream>

#define MAX_N 500000 + 1
#define MAX_P 300000 + 1

using namespace std;

int arr[MAX_N][2];
int onOff[6][MAX_P] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> arr[i][j];
        }
    }

    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        int line = arr[i][0];
        int fret = arr[i][1];
        if (onOff[line][fret] == 0) {
            onOff[line][fret] = 1;
            cnt++;
        }
        for (int j = p - 1; j > fret; --j) {
            if (onOff[line][j] == 1) {
                onOff[line][j] = 0;
                cnt++;
                break;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}