#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct strt {
	int y, x;
	int cost;

	bool operator<(const strt& st)const {
		// 오름차순 cost -> y -> x
		if (cost == st.cost) {
			if (y == st.y) {
				return x > st.x; 
			}
			return y > st.y;
		}
		return cost > st.cost;
	}
	bool operator == (const strt& st) const {
		return y == st.y && x == st.x && cost == st.cost;
	}
};
priority_queue<strt> pq;
vector<strt> vec;

bool cmp(strt a, strt b) {
	if (a.cost == b.cost) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y < b.y;
	}
	return a.cost < b.cost;
}


int main() {
	pq.push({ 0, 0, 0 });
	pq.push({ 1, 1, 0 });
	pq.push({ 2, 3, 10 });
	pq.push({ 1, 5, -2 });
	pq.push({ 1, 6, -2 });



	while (!pq.empty()) {
		strt curr = pq.top();
		pq.pop();
		vec.push_back(curr);
		cout << curr.y << " " << curr.x << " " << curr.cost << "\n";
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i].y << " " << vec[i].x << " " << vec[i].cost << "\n";
	}

	return 0;
}