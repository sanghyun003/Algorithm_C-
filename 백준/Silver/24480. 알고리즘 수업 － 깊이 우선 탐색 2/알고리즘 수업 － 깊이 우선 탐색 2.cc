#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001] = { false };
int cnt = 1;
vector<int> answer(100001,0);

void dfs(int x) {
	visited[x] = true;

	answer[x] = cnt++;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if(!visited[y])
			dfs(y);
	}
}

int main() {
	int N, M, R;
	int u, v;

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(),greater<>());
	}
	dfs(R);
	for (int i = 1; i <= N; i++) {
		cout << answer[i]<<'\n';
	}
	return 0;
}