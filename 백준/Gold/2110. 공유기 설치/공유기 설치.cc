#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can(int d, const vector<int>& v, int N, int C) {

	int cnt = 1;
	int last = v[0];

	for (int i = 1; i < N; i++) {
		if (v[i] - last >= d) {
			cnt++;
			last = v[i];
		}
	}
	return cnt >= C;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, C, num, cnt=0, answer=0, left=0,right=0,mid;
	vector<int> v;


	cin >> N >> C;

	

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	left = 1;
	right = v.back()-v.front();
	while (left <= right) {
		mid = (left + (right-left) / 2);
		if (can(mid, v,N,C)) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}


	cout << answer;

	return 0;
}
