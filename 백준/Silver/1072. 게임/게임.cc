#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long X, Y, Z, cnt = 0;
	int left, right, answer=0;

	cin >> X >> Y;

	Z = Y*100 / X;
	
	left = 0;
	right = X;
	while (left<=right&&Z<99) {
		int mid = left + (right - left) / 2;
		if ((Y + mid) * 100 / (X + mid) == Z) {
			answer = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	if (Z>=99) cout << -1;
	else cout << answer+1;

	return 0;
}