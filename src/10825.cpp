#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 100000

using namespace std;
struct strt {
    string name;
    int kor;
    int eng;
    int math;
};
int N;
vector<strt> vec;
vector<int> v;

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        strt temp; cin >> temp.name >> temp.kor >> temp.eng >> temp.math;
        vec.push_back(temp);
    }
}

bool comp(const strt &a, const strt &b) {
    if (a.kor == b.kor) {
        if (a.eng == b.eng) {
            if (a.math == b.math) {
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.eng < b.eng;
    }
    return a.kor > b.kor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    
    sort(vec.begin(), vec.end(), comp);

    for (int i=0; i<N; ++i) {
        cout << vec[i].name << "\n";
    }

    return 0;
}