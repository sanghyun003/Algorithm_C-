#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K, cnt = 0;

	cin >> N >> K;

	vector<int> v(N);

	for (int i = 0; i<N;i++) {
		cin >> v[i];
	}
	N--;
	while (K > 0) {
		if (K >= v[N]) {
			cnt += K / v[N];
			K %= v[N];
		}
		else N--;
	}
	cout << cnt;

	return 0;
}