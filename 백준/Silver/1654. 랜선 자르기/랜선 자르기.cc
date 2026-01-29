#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int K, N;
	static long long list[100000];
	long long left = 1, right = 1, mid, answer=0;

	cin >> K >> N;
	
	for (int i = 0; i < K; i++) {
		cin >> list[i];
		right = max(right, list[i]);
	}

	while (left <= right) {
		mid = left + (right - left) / 2;
		long long cnt = 0;

		for (int i = 0; i < K; i++) {
			cnt += list[i] / mid;
			if (cnt >= N) break;

		}
		if (cnt>=N) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer;

	return 0;
}
