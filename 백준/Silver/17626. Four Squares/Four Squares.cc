#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int dp[50001] = { 4 };

	for (int i = 0; i < 50001; i++) {
		dp[i] = 4;
	}

	for (int i = 1; i * i < 50000; i++) {
		dp[i * i] = 1;
	}
	for (int i = 1; i*i < 50000; i++) {
		for (int j = i; j*j < 50000; j++) {
			if (i * i + j * j <= 50000 && dp[i*i+j*j]>2) {
				dp[i * i + j * j] = 2;
			}
		}
	}
	for (int i = 1; i * i < 50000; i++) {
		for (int j = i; j * j < 50000; j++) {
			for (int k = j; k * k < 50000; k++) {
				if (i * i + j * j+ k * k <= 50000 && dp[i * i + j * j + k * k] > 3) {
					dp[i * i + j * j + k * k] = 3;
				}
			}
		}
	}

	cin >> n;

	cout << dp[n];

	return 0;
}