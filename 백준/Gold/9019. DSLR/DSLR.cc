#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

inline int D(int n) {
	return 2 * n % 10000;
}
int S(int n) {
	if (n == 0) return 9999;
	return n - 1;
}
inline int L(int n) {
	return n % 1000 * 10 + n / 1000;
}
inline int R(int n) {
	return n % 10 * 1000 + n / 10;
}

string bfs(int start, int end, vector<bool>& visited) {
	queue<pair<int, string>> q;
	q.push(make_pair(start, "a"));
	visited[start] = true;
	while (!q.empty()) {
		pair<int, string> p = q.front();
		q.pop();
		if (p.first == end) return p.second;
		int d = D(p.first);
		int s = S(p.first);
		int l = L(p.first);
		int r = R(p.first);

		if (visited[d] == false) {
			q.push(make_pair(d, p.second + "D"));
			visited[d] = true;
		}
		if (visited[s] == false) {
			q.push(make_pair(s, p.second + "S"));
			visited[s] = true;
		}
		if (visited[l] == false) {
			q.push(make_pair(l, p.second + "L"));
			visited[l] = true;
		}
		if (visited[r] == false) {
			q.push(make_pair(r, p.second + "R"));
			visited[r] = true;
		}
	}
	return "";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	int A, B;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		string answer;
		vector<bool> visited(10000, false);
		answer = bfs(A, B, visited);
		visited.clear();
		cout << answer.substr(1, answer.size()) << '\n';

	}
	return 0;
}