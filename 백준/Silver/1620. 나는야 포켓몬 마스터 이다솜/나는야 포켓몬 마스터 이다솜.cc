#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	string s;
	string input;
	map<int, string> m1;
	map<string, int> m2;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> s;
		m1[i] = s;
		m2[s] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> input;
		if (input[0] <= '9') {
			cout << m1[stoi(input)] << '\n';
		}
		else {
			cout << m2[input] << '\n';
		}
	}
	return 0;
}