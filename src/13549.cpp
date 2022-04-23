#include <iostream>
#include <queue>

#define MAX_N 100000

using namespace std;

int N, K;
bool visited[MAX_N + 3];
struct strt {
    int pos;
    int cost;
    
    // priority_queue 우선순위 바꾸기 
    bool operator < (const strt &s) const {
        return cost > s.cost;
    }
    bool operator > (const strt &s) const {
        return cost < s.cost;
    }
};

void bfs() {
    priority_queue <strt> q;
    // 처음 위치 push
    q.push({N, 0});
    // visited[N] = true;

    while (!q.empty()) {
        strt curr = q.top(); q.pop();
        // cout << "curr.pos : " << curr.pos << "\n";
        if (curr.pos == K) {
            cout << curr.cost << "\n";
            return;
        }

        if (visited[curr.pos]) continue;
        visited[curr.pos] = true;
        
        // if (curr.pos <= 0) {
        //     q.push({curr.pos + 1, curr.cost + 1});
        //     continue;
        // }
        // if (curr.pos > K/2 + 1) {
        //     q.push({curr.pos + 1, curr.cost + 1});
        //     q.push({curr.pos - 1, curr.cost + 1});
        // } else {
        //     q.push({curr.pos + 1, curr.cost + 1});
        //     q.push({curr.pos - 1, curr.cost + 1});
        //     q.push({curr.pos * 2, curr.cost});
        // } 

        if (curr.pos * 2 <= MAX_N) {
            // cout << "111111111\n";
            q.push({curr.pos * 2, curr.cost});
        }
        if (curr.pos + 1 <= MAX_N) {
            // cout << "222222222\n";
            q.push({curr.pos + 1, curr.cost + 1});
        }
        if (curr.pos - 1 >= 0) {
            // cout << "333333333\n";
            q.push({curr.pos - 1, curr.cost + 1});
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    bfs();

    return 0;
}