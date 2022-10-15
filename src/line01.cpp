#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> po;
map<int, pair<int, int>> arr;

int solution(vector<vector<int>> queries) {
    int answer = 0;
    po.push_back(1);
    for(int i=1; i<20; ++i)
        po.push_back(2*po[i-1]);
    for(auto query : queries){
        int arrNum = query[0], eleNum = query[1];
        int arrSizeIdx = lower_bound(po.begin(), po.end(), eleNum) - po.begin();
        if (arr.find(arrNum) == arr.end()) {
            arr[arrNum] = {eleNum, arrSizeIdx};
            continue;
        }
        int oldEleNum = arr[arrNum].first;
        int oldArrSizeIdx = arr[arrNum].second;
        int addEleNum = oldEleNum + eleNum;
        arrSizeIdx = lower_bound(po.begin(), po.end(), addEleNum) - po.begin();
        if (arrSizeIdx > oldArrSizeIdx) {
            arr[arrNum] = {addEleNum, arrSizeIdx};
            answer += oldEleNum;
        } else {
            arr[arrNum] = {addEleNum, arrSizeIdx};
        }
    }

    return answer;
}


//////////////////////


#include <string>
#include <vector>
#include <cmath>

using namespace std;

// long long arrSize;
int a, b;
int sizeArr[1001];  // 각 배열의 크기
int elements[1001]; // 각 배열에 들어있는 원소의 수
int answers[1001];  // 복사한 원소 저장 

void getArrSize(int a, int b) {
    if (sizeArr[a] >= elements[a] + b) {
        elements[a] += b;
        return;
    }
    int i = 0;
    while (sizeArr[a] < elements[a] + b) {
        sizeArr[a] = pow(2, i);
        i++;
    }
    answers[a] += elements[a];
    elements[a] += b;
}

int solution(vector<vector<int>> queries) {
    int answer = 0;

    for (int i=0; i<queries.size(); ++i) {
        a = queries[i][0]; // 배열 번호
        b = queries[i][1]; // 추가할 원소의 수 
        getArrSize(a, b);
    }

    for (int i=0; i<1000; ++i) {
        answer += answers[i];
    }

    return answer;
}