#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int L;
	long long temp, H=0;
	char c;
	const int M = 1234567891;
	int list[50];

	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> c;
		list[i] = c - 'a'+1;
	}

	for (int i = 0; i < L; i++) {
		temp = list[i];
		for (int j = 0; j < i; j++) {
			temp *= 31;
			temp %= M;
		}
		H += temp;
		H %= M;
	}

	cout << H;

	return 0;
}