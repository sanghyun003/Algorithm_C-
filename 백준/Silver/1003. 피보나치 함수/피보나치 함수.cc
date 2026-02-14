#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;
	cin >> T;
	vector<int> v[41];
	v[0] = { 1,0 };
	v[1] = { 0,1 };

	for (int i = 2; i < 41; i++) {
		v[i].push_back(v[i - 1][0] + v[i - 2][0]);
		v[i].push_back(v[i - 1][1] + v[i - 2][1]);
	}

	for (int i = 0; i < T; i++) {
		cin >> n;

		cout << v[n][0] << ' '<< v[n][1] << '\n';
	}

	return 0;
}