#include <iostream>
#include <vector>

#define MAX_N 50

using namespace std;

struct strt {
    int weight;
    int height;
    int rank;
};
int N, x, y;
vector<strt> vec;

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        strt temp; cin >> temp.weight >> temp.height;
        temp.rank = 1;
        vec.push_back(temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    // sort(vec.begin(), vec.end(), comp);
    for (int i=0; i<vec.size(); ++i) {
        for (int j=0; j<vec.size(); ++j) {
            if (vec[i].weight > vec[j].weight && vec[i].height > vec[j].height)
                ++vec[j].rank;
        }
    }

    for (int i=0; i<vec.size(); ++i) {
        cout << vec[i].rank << "\n";
    }

    return 0;
}