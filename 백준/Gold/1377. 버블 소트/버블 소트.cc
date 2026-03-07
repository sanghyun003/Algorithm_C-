#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, answer=0;
	cin >> N;
	vector<pair<int,int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		answer = max(answer,v[i].second - i);
	}
	cout << answer+1;

	return 0;
}