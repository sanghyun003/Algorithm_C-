#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
int visited[101] = { false };

void bfs(int start) {
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : graph[x]) {
			if (!visited[y]) {
				visited[y] = true;
				q.push(y);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, u, v, cnt=0;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	bfs(1);
	for (int i = 2; i <= N;i++) {
		if (visited[i]) cnt++;
	}

	cout << cnt;
	return 0;
}