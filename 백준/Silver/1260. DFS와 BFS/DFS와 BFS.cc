#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


vector<int> graph[1001];
bool check[1001] = { false };

void bfs(int start) {
	bool check[1001] = { false };
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!check[y]) {
				q.push(y);
				check[y] = true;
			}
		}
	}
}

void dfs(int x) {
	check[x] = true;


	cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!check[y]) {
			dfs(y);
		}
	}
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, V;
	int num1, num2;

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(V);
	cout << '\n';
	bfs(V);
	

	return 0;
}
