// 2022 Summer Coding - 여름방학 스타트업 인턴 프로그램 코딩테스트 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> atmos) {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int cntMask = 0;

    int mask = 0;
    int cntDays = 0;

    for (int i = 0; i < atmos.size(); ++i) {
        if (mask >= 1) ++mask;
        if (mask > 3) mask = 0;
        if (mask < 2 && (atmos[i][0] >= 151 && atmos[i][1] >= 76)) {
            ++cntMask;
            mask = 0;
            // cout << "(day " << i << ") mask: " << mask << ", cntMask: " << cntMask << " case0" << "\n";
            continue;
        }
        if (mask == 2 && (atmos[i][0] >= 151 && atmos[i][1] >= 76)) {
            // ++cntMask;
            mask = 0;
            // cout << "(day " << i << ") mask: " << mask << ", cntMask: " << cntMask << " case1" << "\n";
            continue;
        }
        if (mask < 2 && (atmos[i][0] >= 81 || atmos[i][1] >= 36)) {
            ++mask;
            ++cntMask;
            if (atmos[i][0] >= 151 && atmos[i][1] >= 76) {
                mask = 0;
                // cout << "(day " << i << ") mask: " << mask << ", cntMask: " << cntMask << " case2" << "\n";
                continue;
            }
            // cout << "(day " << i << ") mask: " << mask << ", cntMask: " << cntMask << " case3" << "\n";
            continue;
        }
        if (mask == 2 && (atmos[i][0] >= 81 || atmos[i][1] >= 36)) {
            // ++mask;
            // cout << "(day " << i << ") mask: " << mask << ", cntMask: " << cntMask << " case4" << "\n";
            continue;
        }
        // cout << "(day " << i << ") mask: " << mask << ", cntMask: " << cntMask << " case5" << "\n";
    }

    // cout << "(LAST DAY) mask: " << mask << ", cntMask: " << cntMask << "\n";

    return cntMask;
}