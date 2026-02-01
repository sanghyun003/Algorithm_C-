#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	unordered_map<string, string> m;
	string site, password;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> site>>password;
		m[site] = password;
	}
	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << m[site] << '\n';
	}
	return 0;
}