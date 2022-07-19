#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> vec;

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        vec.push_back(temp);
    }
    cin >> K;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    for (int i=0; i<N; i+=N/K) { 
        sort(vec.begin()+i, vec.begin()+i+N/K);
    }
    for (int i=0; i<N; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
    
    // for (auto iter = vec.begin(); iter != vec.end(); iter += N/K){
    //     sort(iter, iter + N/K);
    // }

    return 0;
}