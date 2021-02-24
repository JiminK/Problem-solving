#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int t, n, answer;

int findMaxCrossingSubarray(vector<int>& param0, const int& low, int& mid, int& high) {
    // mid 부터 왼쪽으로
    int left_sum = INT_MIN; // 음의 무한대
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += param0[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    // mid + 1 부터 오른쪽으로
    int right_sum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += param0[j];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    int crossSum = left_sum + right_sum;
    return crossSum;
}

int findMaxSubarray(vector<int>& param0, const int& low, int& high) {
    // 원소가 한 개인 경우
    if (high == low)
        return (param0[low]);

    else {
        int answer = 0;
        int leftSum, rightSum, crossSum;
        int mid = (low + high) / 2;

        leftSum = findMaxSubarray(param0, low, mid);
        rightSum = findMaxSubarray(param0, mid + 1, high);
        crossSum = findMaxCrossingSubarray(param0, low, mid, high);

        // 세 수 비교
        if (leftSum >= rightSum) {
            if (leftSum >= crossSum)
                answer = leftSum;
            else
                answer = crossSum;
        }
        else { // left_sum < right_sum 
            if (rightSum >= crossSum)
                answer = rightSum;
            else
                answer = crossSum;
        }
        // 가장 큰 수 리턴
        return answer;
    }
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> v(n + 1);
        int low = 0, high = n - 1;
        for (int j = 0; j < n; j++) {
            cin >> v[j];
		}
        answer = findMaxSubarray(v, low, high);
        cout << answer << endl;
	}
	return 0;
}
