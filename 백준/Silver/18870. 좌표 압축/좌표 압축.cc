#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, X, cnt=0;
	map<int, int> m;
	vector<int> v;
	v.reserve(1000000);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X;
		v.push_back(X);
		m[X]=0;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		it->second = cnt++;
	}
	for (int i = 0; i < N; i++) {
		cout << m[v[i]] << ' ';
	}

	return 0;
}