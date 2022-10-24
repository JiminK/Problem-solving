#include <iostream>
#include <vector>

using namespace std;

struct strt{
    int r, c;
};
int MAP[9][9];
vector<strt> blank;
bool checkRow[9][9];
bool checkCol[9][9];
bool checkSquare[3][3][9];
bool finish;

void dfs(int cnt) {
    if (finish) return;
    if (cnt == blank.size()) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << MAP[i][j] << " ";
            }
            cout << "\n";
        }
        finish = true;
        return;
    }

    int r = blank[cnt].r, c = blank[cnt].c;
    for (int i=0; i<9; ++i) {
        if (checkRow[r][i] || checkCol[c][i] || checkSquare[r/3][c/3][i]) continue;
        checkRow[r][i] = true;
        checkCol[c][i] = true;
        checkSquare[r/3][c/3][i] = true;

        MAP[r][c] = i+1; // 0인 칸에 1부터 9까지 넣어보기 
        dfs(cnt+1);
        
        // 상태 복원  
        checkRow[r][i] = false;
        checkCol[c][i] = false;
        checkSquare[r/3][c/3][i] = false;

    }
    // 상태 복원할 필요 없다.
    // MAP[r][c] = 0;
    return;
}

void solve(int cnt) {
    dfs(cnt);
}

void getInput() {
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            int temp; cin >> temp;
            MAP[i][j] = temp;
            if (temp == 0) blank.push_back({i, j});
            else {
                checkRow[i][temp - 1] = true;
                checkCol[j][temp -1 ] = true;
                checkSquare[i/3][j/3][temp - 1] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve(0);

    return 0;
}

/*
빈칸에 대해 dfs 호출

종료조건 → 빈칸의 개수 활용

가지치기 → 스도쿠 조건 활용 
(빈칸을 채웠을 때, 해당 빈칸의 가로세로/둘러싸고 있는 칸 확인)

⇒ 가로줄 빠르게 확인하는 방법 
; 가로크기만큼의 일차원 배열 → 들어 있는 숫자 true, false 로 체크
*/