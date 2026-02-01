#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	string name, category;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int answer = 1;
		unordered_map<string, int> m;

		cin >> M;

		for (int j = 0; j < M; j++) {
			cin >> name >> category;
			m[category]++;
		}
		for (const auto& c : m) {
			answer *= c.second + 1;
		}
		cout << answer - 1 << '\n';
	}

	return 0;
}