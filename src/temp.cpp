#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector< vector<int> > sij(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sij[i][j] << " ";

        }
        cout << "\n";
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> sij[i][j];
        }
    }

    int sTeam = 0, lTeam = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sij[i][j] << " ";

        }
        cout << "\n";
    }

    return 0;
}