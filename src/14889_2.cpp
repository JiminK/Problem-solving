#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 22

// vector< vector<int> > sij(MAX_N, vector<int>(MAX_N, 0));
vector< vector<int> > sij;
// int sTeam[MAX_N / 2], lTeam[MAX_N / 2]; // team combination
vector< vector<int> > sTeam;
vector< vector<int> > lTeam;
vector<int> member;
vector<int> c;

void combination(vector<int> v, vector<int> c, int r, int idx, int depth, int halfN) {
    if (r == 0) {
        vector<int> sTmp;
        vector<int> lTmp;
        for (int i = 0; i < c.size(); ++i) {
            cout << c[i] << ",";
            if (c[i] != 0) { // sTeam
                sTmp.push_back(c[i]);
                
            } else { // lTeam
                lTmp.push_back(v[i]);
            }
        }cout << "\n";
        sTeam.push_back(sTmp);
        lTeam.push_back(lTmp);
    } else if (depth == v.size()) {
        return;
    } else {
        c[idx] = v[depth];
        combination(v, c, r - 1, idx + 1, depth + 1, halfN);
        combination(v, c, r, idx, depth + 1, halfN);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    // cout << "n: " << n << "\n";
    int halfN = n / 2;
    // cout << "halfN: " << halfN;

    for (int i = 0; i < n; ++i) {
        member.push_back(i + 1);
    }
    for (int i = 0; i < n; ++i) {
        vector<int> tmp;
        for (int j = 0; j < n; ++j) {
            int tempNum;
            cin >> tempNum;
            tmp.push_back(tempNum);
        }
        sij.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        c.push_back(0);
    }
    combination(member, c, halfN, 0, 0, halfN);
    for (int i = 0; i < sTeam.size(); ++i) {
        for (int j = 0; j < halfN; ++j) {
            cout << sTeam[i][j] << " ";
        }
        cout << "\n";
    }

    int sTeamScore = 0, lTeamScore = 0;
    

    return 0;
}