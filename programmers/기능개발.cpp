#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> stk;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> leftProgresses;
    for (int i=0; i<progresses.size(); ++i) {
        int tmp = (100 - progresses[i]) / speeds[i];
        if (((100 - progresses[i]) % speeds[i]) > 0) {
            ++tmp;
        }
        leftProgresses.push_back(tmp);
        // cout << leftProgresses[i] << " ";
    }
    
    stk.push(leftProgresses[0]);
    int cnt = 0;
    for (int i=1; i<leftProgresses.size(); ++i) {
        // cout << stk.top() << ", " << leftProgresses[i] << "\n";
        if (stk.top() < leftProgresses[i]) {
            stk.pop();
            ++cnt;
            answer.push_back(cnt);
            cnt = 0;
            stk.push(leftProgresses[i]);
        }
        else if (stk.top() >= leftProgresses[i]) 
            ++cnt;
    }
    while (!stk.empty()) {
        stk.pop();
        ++cnt;
    }
    answer.push_back(cnt);
    
    return answer;
}