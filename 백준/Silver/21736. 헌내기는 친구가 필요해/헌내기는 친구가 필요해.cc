#include <iostream>
#include <queue>

using namespace std;

char c[601][601];
bool visited[601][601];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;

void bfs(pair<int, int> s,int M, int N) {
	queue<pair<int, int>> q;
	q.push(s);
	visited[s.second][s.first] = true;
	while (!q.empty()) {
		int y = q.front().second;
		int x = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int lx = x + dx[i];
			int ly = y + dy[i];
			if (lx > 0 && lx <= M && ly>0 && ly <= N && visited[ly][lx] == false && c[ly][lx] != 'X') {
				if (c[ly][lx] == 'P')cnt++;
				q.push(make_pair(lx, ly));
				visited[ly][lx] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	pair<int, int> s;

	cin >> N >> M;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> c[y][x];
			if (c[y][x] == 'I') s = make_pair(x, y);
		}
	}
	bfs(s,M,N);
	if (cnt == 0) cout << "TT";
	else cout << cnt;
	return 0;
}