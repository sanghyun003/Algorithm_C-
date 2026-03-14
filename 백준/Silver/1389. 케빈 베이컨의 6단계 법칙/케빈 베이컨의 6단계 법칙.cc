#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[101];
vector<int> kb_v(101);

int bfs(int start,int N) {
	queue<int> q;
	q.push(start);

	vector<int> visited(N + 1,-1);
	visited[start] = 0;

	int ret = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0;i < v[x].size();i++) {
			int y = v[x][i];
			if (visited[y] == -1) {
				q.push(y);
				visited[y] = visited[x] + 1;
			}
		}
	}
	for (int i = 1;i <=N;i++) {
		ret += visited[i];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	int A, B;
	int answer = 10000;
	int dap = 0;

	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}

	for (int i = 1;i <= N;i++) {
		kb_v[i] = bfs(i,N);
	}

	for (int i = 1;i <= N;i++) {
		if (answer > kb_v[i]) {
			answer = kb_v[i];
			dap = i;
		}
	}
	cout << dap;

	return 0;
}