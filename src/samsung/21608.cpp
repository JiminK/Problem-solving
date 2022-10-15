#include <iostream>
#include <vector>

#define MAXN 20
using namespace std;

int N;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int student[MAXN*MAXN+1][5];
bool check[MAXN+1][MAXN+1];

int result; // 만족도의 합

void getInput() {
    cin >> N;
    for (int i=0; i<N*N; ++i) {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}

/*
1. 비어있는 칸 중에서 
    좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
2. 1을 만족하는 칸이 여러 개이면, 
    인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
3. 2를 만족하는 칸도 여러 개인 경우에는 
    행의 번호가 가장 작은 칸으로, 
    그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
*/