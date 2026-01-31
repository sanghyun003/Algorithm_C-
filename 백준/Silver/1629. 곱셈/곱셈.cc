#include <iostream>

using namespace std;

long long function(long long A, long long B, long long C) {
	if (B == 0) return 1;
	long long half = function(A, B / 2, C);


	if (B % 2 == 1) return half * half % C * A % C;
	else return half * half % C;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long A, B, C;
	cin >> A >> B >> C;

	cout << function(A,B,C);

	return 0;
}