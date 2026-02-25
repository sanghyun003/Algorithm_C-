#include <iostream>
#include <cmath>

using namespace std;

int solution(int result,int r, int c, int N) {
	if (N == 1) return 2 * r + c;

	int k = pow(2, N - 1);
	if (r < k) {
		if (c < k) {
			result += 0 * pow(k, 2)+ solution(result, r, c, N - 1);
		}
		else {
			result += 1 * pow(k, 2)+ solution(result, r, c-k, N - 1);
		}
	}
	else {
		if (c < k) {
			result += 2 * pow(k, 2)+ solution(result, r-k, c, N - 1);
		}
		else {
			result += 3 * pow(k, 2)+ solution(result, r-k, c-k, N - 1);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, r, c;
	int result = 0;

	cin >> N >> r >> c;

	cout <<solution(result, r, c, N);

	return 0;
}