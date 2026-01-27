#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, num, left=0, right=0, mid=0;
	long long total=0;

	cin >> N >> M;

	vector<int> list(N);

	for (int i = 0; i < N; i++) {
		cin >> num;
		list[i] = num;
		right = max(right, num);
	}

	while (left <= right) {
		mid = (left + right) / 2;
		total = 0;
		for (int i = 0; i < N; i++) {
			total += max(list[i] - mid, 0);
		}
		if (total >= M) {
			left = mid+1;
		}
		else {
			right = mid-1;
		}
	}

	cout << right;

	return 0;
}