#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 22

// vector< vector<int> > sij(MAX_N, vector<int>(MAX_N, 0));
vector< vector<int> > sij;
// int sTeam[MAX_N / 2], lTeam[MAX_N / 2]; // team combination
vector< vector<int> > sTeam;
// vector< vector<int> > lTeam;
vector<int> member;
vector<int> c;

void combination(vector<int> v, vector<int> c, int r, int idx, int depth) {
    if (r == 0) {
        vector<int> sTmp;
        // vector<int> lTmp;
        for (int i = 0; i < c.size(); ++i) {
            // cout << c[i] << ",";
            if (c[i] != 0) { // sTeam
                sTmp.push_back(c[i]);
            } 
            // if (c[i] == 0) { // lTeam
            //     // cout << v[i] << ",";
            //     lTmp.push_back(i);
            //     // cout << lTmp[i] << ",";
            // }
        }
        sTeam.push_back(sTmp);
        // lTeam.push_back(lTmp);
    } else if (depth == v.size()) {
        return;
    } else {
        c[idx] = v[depth];
        combination(v, c, r - 1, idx + 1, depth + 1);
        combination(v, c, r, idx, depth + 1);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n; cin >> n;
    // cout << "n: " << n << "\n";
    
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
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << sij[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < n; ++i) {
        c.push_back(0);
    }
    
    combination(member, c, n/2, 0, 0);
    // for (int i = 0; i < sTeam.size(); ++i) {
    //     for (int j = 0; j < n / 2; ++j) {
    //         cout << sTeam[i][j] << ",";
    //     }
    //     cout << "\n";
    // }

    vector<int> sTeamScoreVec, lTeamScoreVec;
    for (int i = 0; i < sTeam.size(); ++i) {
        int sTeamScore = 0;
        for (int j = 0; j < sTeam[i].size(); ++j) {
            int nowI = sTeam[i][j] - 1;
            int nowJ = sTeam[i][j+1] - 1;
            cout << "nowI, nowJ : " << nowI << ",   ";
            // cout << sij[nowI][nowJ] << "," << sij[nowJ][nowI];
            cout << nowJ << "\n";
            sTeamScore = sij[nowI][nowJ] + sij[nowJ][nowI];
            // cout << sTeamScoreVec[i] << "\n";
        }
        sTeamScoreVec.push_back(sTeamScore);

    }
    // for (int i = sTeam.size() - 1; i >= sTeam.size()/2; --i) {
    //     int lTeamScore = 0;
    //     int nowI = sTeam[i][i] - 1;
    //     // cout << "nowI, nowJ : " << nowI << ", ";
    //     int nowJ = sTeam[i][i+1] - 1;
    //     // cout << sij[nowI][nowJ] << "," << sij[nowJ][nowI];
    //     // cout << nowJ << "\n";
    //     lTeamScore = sij[nowI][nowJ] + sij[nowJ][nowI];
    //     lTeamScoreVec.push_back(lTeamScore);
    //     cout << lTeamScore << "\n";
    // }
    
    int minDiff = sTeamScoreVec[0];
    for (int i = 0; i < sTeam.size()/2; ++i) {
        int tmp = abs(sTeamScoreVec[i] - lTeamScoreVec[i]);
        if (minDiff > tmp)
            minDiff = tmp;
        else   
            continue;
    }
    // cout << minDiff << "\n";
    return 0;
}