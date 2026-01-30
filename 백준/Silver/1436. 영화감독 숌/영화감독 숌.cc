#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, cnt=1;
	int answer = 666;
	string s = "666";

	cin >> N;

	while (cnt < N) {
		answer++;
		if (to_string(answer).find(s) != string::npos) cnt++;
	}
	cout << answer;

	return 0;
}