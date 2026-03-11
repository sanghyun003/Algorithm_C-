#include <iostream>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<int> q;
	map<int,int> m;
	bool visited[101] = { false };
	int N, M;
	int u, v;
	int answer = 0;
	bool e = true;

	cin >> N >> M;

	for (int i = 0; i < N+M; i++) {
		cin >> u >> v;
		m[u]=v;
	}

	q.push(1);
	while (!q.empty()&&e) {
		int size = q.size();
		for (int k = 0; k < size; k++) {
			int x = q.front();
			q.pop();
			bool check = true;
			if (x == 100) {
				e = false;
				break;
			}
			for (int i = 6; i >= 1; i--) {
				int y = x + i;
				if (y <= 100) {
					if (m.find(y) != m.end()) {
						if (visited[m[y]] ==false) {
							visited[m[y]] = true;
							q.push(m[y]);
						}
						m.erase(y);
					}
					else {
						if (check) {
							if (visited[y]==false) {
								visited[y] = true;
								q.push(y);
								check = false;
							}
						}
					}
				}
			}
		}
		answer++;
	}

	cout << answer-1;

	return 0;
}