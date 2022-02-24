#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int minPack = 1000, minOne = 1000;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        if (minPack > a)
            minPack = a;
        if (minOne > b)
            minOne = b;
    }

    int minPrice, x, y, z;
    /* case 1: buy only package string */
    if (n % 6 == 0) {
        x = (n / 6) * minPack;   
    } else {
        x = (n / 6 + 1) * minPack;
    }
    /* case 2: buy package string as much as possible and then buy single one */
    y = (n / 6) * minPack + (n % 6) * minOne;
    /* case 3: buy only single string */
    z = n * minOne;
    // cout << x << " " << y << " " << z << "\n";

    minPrice = min(x, y);
    minPrice = min(minPrice, z);
    cout << minPrice << "\n";

    return 0;
}