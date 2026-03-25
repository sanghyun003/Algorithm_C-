#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> bfs(const vector<vector<int>>& graph, const int& R, const int& N) {
	vector<int> visited(N+1);
	queue<int> q;
	int cnt = 1;

	q.push(R);
	visited[R] = cnt++;

	while (!q.empty()) {
		int y = q.front();
		q.pop();

		for (int x : graph[y]) {
			if (visited[x] == 0) {
				q.push(x);
				visited[x] = cnt++;
			}
		}
	}
	return visited;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, R;
	int u, v;

	cin >> N >> M >> R;
	vector<vector<int>> graph(N+1);

	for (int i = 0;i < M;i++) {
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	for (int i = 1;i <= N;i++) {
		sort(graph[i].begin(), graph[i].end(),greater<>());
	}

	vector<int> answer = bfs(graph, R, N);

	for (int i = 1;i <= N;i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}