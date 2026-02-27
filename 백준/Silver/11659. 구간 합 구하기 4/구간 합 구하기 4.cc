#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, x, y, t;
	vector<long long> sv;
	sv.push_back(0);
	sv.reserve(100001);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> t;
		sv.push_back(sv[i - 1] + t);
	}

	for (int i = 0; i < M; i++) {
		int answer = 0;
		cin >> x >> y;
		cout << sv[y] - sv[x-1] << '\n';
	}

	return 0;
}