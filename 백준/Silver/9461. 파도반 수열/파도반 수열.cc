#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		N--;
		vector<long long> v{ 1,1,1,2,2 };
		for (int j = 0; j < N / 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (k == 0) v[k] = v[k] + v[k + 4];
				else v[k] = v[k] + v[k - 1];
			}
		}
		cout << v[N % 5]<<'\n';
	}
	return 0;
}