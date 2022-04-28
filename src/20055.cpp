#include <iostream>
#include <deque>

#define MAX_N 100

using namespace std;

int N, K;
struct strt {
    int pos; // 1~2N 
    int ai; // 내구도 
    bool onRobot; // 로봇이 있는지 
};
deque<strt> belt1;
deque<strt> belt2;
int cntStep;
strt upPos, downPos, currPos, nextPos;

void getInput() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        // belt1[i].pos = i + 1;
        int tmp; cin >> tmp;
        belt1.push_back({i + 1, tmp, false});
    }
    // for (int i = N - 1; i >= 0; --i) {
    //     belt2[i].pos = 2 * N - i;
    //     cin >> belt2[i].ai;
    // }
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp;
        belt2.push_front({N + i + 1, tmp, false});
    }
}

void printBelt() {
    for (int i = 0; i < N; ++i) {
        cout << belt1[i].pos << " " << belt1[i].ai << " " << belt1[i].onRobot << "\n";
    }
    cout << "-------\n";
    for (int i = N - 1; i >= 0; --i) {
        cout << belt2[i].pos << " " << belt2[i].ai << " " << belt2[i].onRobot << "\n";
    }
    cout << "===========\n";

}

void moveRobot() { // seq 2 
/* 
가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 
만약 이동할 수 없다면 가만히 있는다.
로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
*/
    for (int i = N - 1; i >= 0; --i) {
        if (belt1[i].onRobot == true && belt1[i + 1].onRobot == false && belt1[i + 1].ai > 0) {
            // --belt1[i].ai;
            belt1[i].onRobot = false;
            --belt1[i + 1].ai;
            belt1[i + 1].onRobot = true;
            // cout << "i : " << i << "\n";
        }
        else continue;
    }
    

}

void upRobot() { // seq 3 
    // 올리는 위치에 있는 칸(belt1.front())의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
    upPos = belt1.front(); belt1.pop_front();
    // cout << "upPos.ai : " << upPos.ai << "\n";
    if (upPos.ai > 0) {
        --upPos.ai;
        upPos.onRobot = true; 
    }
    belt1.push_front(upPos);
}

bool checkEnd() { // seq 4 
    int cntZero = 0;
    for (int i = 0; i < N; ++i) {
        if (belt1[i].ai == 0) ++cntZero;
        if (belt2[i].ai == 0) ++cntZero;
    }
    if (cntZero >= K) return true;
    return false;
}

void rotate() { // seq 1
    belt1.push_front(belt2.front());
    belt2.pop_front();
    belt2.push_back(belt1.back());
    belt1.pop_back();
}

void downRobot() {
    // 내리는 위치에 있는 칸(belt1.back())에 로봇이 있으면 내린다.
    downPos = belt1.back(); belt1.pop_back();
    if (downPos.onRobot == true) {
        downPos.onRobot = false; 
    }
    belt1.push_back(downPos);
}

void solve() {
    getInput();
    while (!checkEnd()) {
        rotate();
        // cout << "rotate\n";
        // printBelt();

        downRobot();
        // cout << "downRobot\n";
        // printBelt();

        moveRobot();
        // cout << "moveRobot\n";
        // printBelt();
                
        downRobot();
        // cout << "downRobot\n";
        // printBelt();

        upRobot();
        // cout << "upRobot\n";
        // printBelt();

        downRobot();
        // cout << "downRobot\n";
        // printBelt();
        ++cntStep;
    }
    cout << cntStep << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}