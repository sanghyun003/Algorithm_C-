#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int* dp = new int[1000001];
	dp[1] = 0;
	
	for (int i = 2; i < 1000001; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2]) dp[i] = dp[i / 2]+1;
		if (i % 3 == 0 && dp[i] > dp[i / 3]) dp[i] = dp[i / 3]+1;
	}

	cin >> N;

	cout << dp[N];

	return 0;
}