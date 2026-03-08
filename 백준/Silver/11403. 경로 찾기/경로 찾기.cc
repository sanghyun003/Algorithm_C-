#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, tmp;
	vector<vector<int>> v(100,vector<int>(100,0));
	vector<vector<int>> graph(100);


	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 1) graph[i].push_back(j);
		}
	}

	for (int i = 0; i < N; i++) {
		bool visited[100] = { false };
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int j = 0; j < graph[x].size(); j++) {
				if (visited[graph[x][j]] == false) {
					q.push(graph[x][j]);
					v[i][graph[x][j]] = 1;
					visited[graph[x][j]] = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}