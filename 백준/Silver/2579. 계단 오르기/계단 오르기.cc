#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, x;
	int dp[301] = { 0 };
	int dp2[301] = { 0 };
	bool check[301] = { false };

	dp[0] = 0;

	cin >> N;
	cin >> dp[1];

	for (int i = 2; i <= N; i++) {
		cin >> x;

		if (check[i - 1] == true) {
			if (dp2[i - 1] > dp[i - 2]) {
				dp[i] = x + dp2[i - 1];
				check[i] = true;
				dp2[i] = x + dp[i - 2];
			}
			else dp[i] = x + dp[i - 2];
		}
		else {
			if (dp[i - 2] >= dp[i - 1]) {
				dp[i] = x + dp[i - 2];
			}
			else {
				dp[i] = x + dp[i - 1];
				check[i] = true;
				dp2[i] = x + dp[i - 2];
			}
		}
	}
	cout << dp[N];

	return 0;
}