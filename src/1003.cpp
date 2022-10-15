#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> vec;

void fibo() {
    
}

void getInput() {
    cin >> T;
    for (int i=0; i<T; ++i) {
        int temp; cin >> temp;
        vec.push_back(temp);
    }
    fibo();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();


    return 0;
}