#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph(1001);
vector<bool> visited(1001);

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (visited[y] == false) dfs(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, u, v;
	int answer = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] ==false) {
			dfs(i);
			answer++;
		}
	}
	cout << answer;

	return 0;
}