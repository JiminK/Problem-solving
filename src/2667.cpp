#include <iostream>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // r, d, l, u
bool visited[25][25];

int dfs(int row, int col) {
    if (row < 0 || row > 25 || col < 0 || col > 25){
        return 0;
    }
    if (visited[row][col]){
        return 0;
    }

    for(int i=4;;){
        int nextRow = row + dir[i][0];
        int nextCol = col + dir[i][1];
        if(visited[nextRow][nextCol]){
            continue;
        }
    }
}

int main() {
    int n;
    int arr[25][25];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
           cin >> arr[i][j];
        }
    }




    return 0;
}