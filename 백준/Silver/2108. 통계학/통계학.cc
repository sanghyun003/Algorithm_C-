#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, num, total=0, mid_val=0, cnt=0, max_cnt=0,max_cnt_val=0, max_val=-4000, min_val=4000;
	map<int, int> m;
	bool check = false;

	cin >> N;
	int mid_idx = N / 2;

	for (int i = 0; i < N; i++) {
		cin >> num;
		m[num]++;
		total += num;
		max_val = max(num, max_val);
		min_val = min(num, min_val);
		max_cnt = max(max_cnt, m[num]);
	}
	for (auto& i : m) {
		cnt += i.second;
		if (cnt > mid_idx) {
			mid_val = i.first;
			break;
		}
	}
	cnt = 0;
	for (auto& i : m) {
		if (i.second == max_cnt) {
			cnt++;
			max_cnt_val = i.first;
			if (cnt == 2) break;
		}
	}


	cout << (int)round((double)total/N)<< '\n';
	cout << mid_val << '\n';
	cout << max_cnt_val << '\n';
	cout << max_val - min_val << '\n';

	return 0;
}