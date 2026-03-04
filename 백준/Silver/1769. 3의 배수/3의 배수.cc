#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int X=0, answer = 0, cnt = 0;
	string s;
	
	cin >> s;
	if (s.size() > 1) {
		for (char i:s) {
			X += i - '0';
		}
		cnt++;
	}
	else {
		X = s[0] - '0';
	}

	while (X / 10 > 0) {
		answer += X % 10;
		while (X / 10 > 0) {
			X /= 10;
			answer += X % 10;
		}
		X = answer;
		answer = 0;
		cnt++;
	}

	cout << cnt << '\n';
	cout << ((X % 3 == 0) ? "YES" : "NO");

	return 0;
}