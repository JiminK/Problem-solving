#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    if (v1[1] == v2[1]) // E 같다 => S 작은 순서로 정렬
        return v1[0] < v2[0];
    else // E 다르다 => E 작은 순서로 정렬
        return v1[1] < v2[1];
}

int main()
{
    int N = 0, answer = 1;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(2,0));
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    int n = arr.size();

    sort(arr.begin(), arr.end(), cmp);

    int end_time = arr[0][1]; // 회의가 끝나는 시각 저장
    for (int i = 1; i < n; i++) {
        if (end_time <= arr[i][0]) { // 현재 회의의 끝나는 시각이 다음 회의 시작 시각보다 빠르면 다음 팀이 회의 가능하므로
            end_time = arr[i][1]; // 다음 회의의 끝나는 시간을 저장
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}