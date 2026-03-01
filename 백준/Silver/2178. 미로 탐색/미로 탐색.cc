#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<int>> v(100,vector<int>(100));

void bfs(int fx, int fy, int N, int M) {
	queue<pair<int,int>> q;
	q.push(make_pair(fx,fy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int lx = x + dx[i];
			int ly = y + dy[i];
			if (lx >= 0 && lx < M && ly >= 0 && ly < N && v[ly][lx] == 1) {
				v[ly][lx] = v[y][x]+1;
				q.push(make_pair(lx, ly));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	string s;
	char c;

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		cin >> s;
		stringstream ss(s);
		for (int x = 0; x < M; x++) {
			ss >> c;
			v[y][x] = c - '0';
		}
	}
	bfs(0, 0, N, M);

	cout << v[N - 1][M - 1];

	return 0;
}