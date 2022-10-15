#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>

using namespace std;

int L, C;
vector<char> vec;
vector<char> answer;
// int cons, vowel;

void dfs(int idx, string currWord) {
    // 완료 탈출
    if (currWord.size() == L) {
        int vowel = 0, cons = 0;
        for (int s=0; s<currWord.size(); ++s) {
            if (currWord[s] == 'a' || currWord[s] == 'e' || currWord[s] == 'i' || currWord[s] == 'o' || currWord[s] == 'u') {
                ++vowel;
            } else {
                ++cons;
            }
        }
        if (cons >= 2 && vowel >= 1) {
            cout << currWord << "\n";
            return;
        }
        return;
    }
    // idx 를 넘어갔을 때
    if (idx >= C) return;

    // cout << "currWord: " << currWord << "\n";
    // 뽑았을 때
    currWord += vec[idx];
    dfs(idx + 1, currWord);

    // 안 뽑았을 때
    currWord.pop_back();
    dfs(idx + 1, currWord);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> L >> C;
    for (int i=0; i<C; ++i) {
        char temp; cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());

    dfs(0, "");
    
    return 0;
}