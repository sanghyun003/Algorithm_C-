#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K, num, sum=0;
	int list[100000] = { 0, };
	int left = 0, right = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num;
		list[i] = num;
	}

	right = K-1;

	for (int i = left; i <= right; i++) {
		sum += list[i];
	}

	int t_max = sum;

	while (right < N) {
		if (sum > t_max) t_max = sum;
		sum -= list[left];
		left++;
		right++;
		sum += list[right];
	}

	cout << t_max;

	return 0;
}