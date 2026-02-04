#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> area(51, vector<int>(51, 0));
vector<vector<bool>> visited(51, vector<bool>(51, false));

void dfs(int x,int y, int M, int N) {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	visited[y][x] = false;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N && visited[ny][nx]==true) {
			dfs( nx, ny, M, N);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, M, N, K;
	int X, Y;

	cin >> T;

	while (T-- > 0) {

		int cnt = 0;

		cin >> M >> N >> K;

		for (int y = 0; y < 51; y++) {
			for (int x = 0; x < 51; x++) {
				area[y][x] = 0;
				visited[y][x] = false;
			}
		}
		
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			area[Y][X] = 1;
			visited[Y][X] = true;
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M;x++ ) {
				if (visited[y][x] == true) {
					dfs(x, y, M, N);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}