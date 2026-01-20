#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	long long num, max_cnt=0, max=0;
	map<long long, int> m;

	cin >> N;

	while (N-- > 0) {
		cin >> num;
		m[num]++;
	}
	for (auto& c : m) {
		if (c.second > max_cnt) {
			max = c.first;
			max_cnt = c.second;
		}
	}
	cout << max;
	return 0;
}