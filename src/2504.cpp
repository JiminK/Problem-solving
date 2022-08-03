#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> bracket;
int answer;
int temp = 1;

void solve(string str) {
    for (int i=0; i<str.size(); ++i) {
        char curr = str[i];
        // cout << "\n===========\n";
        // cout << curr << " " << answer << " ";
        if (curr == '(') {
            bracket.push(curr);
            temp *= 2;
            continue;
        }
        if (curr == '[') {
            bracket.push(curr);
            temp *= 3;
            continue;
        }
        // char prev = str[i-1];
        if (curr == ')') {
            if (bracket.empty() || bracket.top() != '(') {
                answer = 0;
                return;
            }
            if (str[i-1] == '(') {
                answer += temp;
                temp /= 2;
                bracket.pop();
            }
            else {
                temp /= 2;
                bracket.pop();
            }
        }
        if (curr == ']') {
            if (bracket.empty() || bracket.top() != '[') {
                answer = 0;
                return;
            }
            if (str[i-1] == '[') {
                answer += temp;
                temp /= 3;
                bracket.pop();
            }
            else {
                temp /= 3;
                bracket.pop();
            }
        }
    }
    // 다 끝났는데 스택에 괄호가 남아있으면 올바르지 않은 괄호열이 아님 
    if (!bracket.empty()) answer = 0;
}

void getInput() {
    string temp; cin >> temp;
    solve(temp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << answer << "\n";

    return 0;
}

// https://mjmjmj98.tistory.com/70 