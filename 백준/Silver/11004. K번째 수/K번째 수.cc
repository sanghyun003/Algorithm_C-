#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	int x;
	vector<int> v;
	v.reserve(5000000);

	cin >> N >> K;

	for (int i = 0;i < N;i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	cout << v[K - 1];

	return 0;
}