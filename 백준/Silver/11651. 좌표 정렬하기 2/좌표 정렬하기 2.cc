#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, x, y;
	vector<pair<int, int>> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), cmp);

	for (pair<int, int> p : v) {
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}