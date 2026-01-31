#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, N;
	int answer=0;
	int list[1000000] = { 0 };

	cin >> A >> B >> N;

	answer = A % B;
	for (int i = 0; i < N; i++) {
		answer *= 10;
		list[i] = answer / B;
		answer = answer % B;
	}
	cout << list[N-1];

	return 0;
}