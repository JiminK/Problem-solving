#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;

void func(int cnt, vector<int> result, int cur){
    if(cnt == 6){
        for(auto c : result){
            cout << c << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i = 0; i<vec.size(); i++){
        if(vec[i] <= cur)continue;
        result.push_back(vec[i]);
        func(cnt+1, result, vec[i]);
        result.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(1){
        int x;
        cin >> x;
        if(x == 0)break;
        for(int i = 0; i<x; i++){
            int n; cin >> n;
            vec.push_back(n);
        }
        sort(vec.begin(), vec.end());
        vector<int> res;
        func(0, res, -1);
        
        vec.clear();
        cout << '\n';
    }
    return 0;
}