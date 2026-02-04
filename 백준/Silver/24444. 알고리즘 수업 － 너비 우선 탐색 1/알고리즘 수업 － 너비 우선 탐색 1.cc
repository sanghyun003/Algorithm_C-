#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001] = { false };
int cnt = 1;
vector<int> answer(100001,0);

void bfs(int start) {
	queue<int> q;
	q.push(start);

	visited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		answer[x] = cnt++;
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, R;
	int u, v;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		cin >> u>> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	bfs(R);

	for (int i = 1; i <= N; i++) {
		cout << answer[i]<<'\n';
	}

	return 0;
}