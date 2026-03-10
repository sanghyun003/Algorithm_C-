#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, H;
	int num = 0;
	bool check = false;
	queue<pair<int, int>> q;

	cin >> N >> M >> H;

	vector<vector<int>> v(M * H, vector<int>(N));

	for (int z = 0; z < H; z++) {
		for (int y = 0; y < M; y++) {
			for (int x = 0; x < N; x++) {
				cin >> num;
				v[y + M * z][x] = num;
				if (num == 0)check = true;
				else if (num == 1) q.push(make_pair(x, y + M * z));
			}
		}
	}
	if (!check) {
		cout << 0;
		return 0;
	}
	int dx[6] = { -1,1,0,0,0,0 };
	int dy[6] = { 0,0,-1,1,-M,M };
	int day = 0;
	while (!q.empty()) {
		int q_size = q.size();
		for (int k = 0; k < q_size; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				if (y % M == 0 && i == 2) continue;
				if (y % M==M-1 && i == 3) continue;
				int lx = x + dx[i];
				int ly = y + dy[i];
				if (lx >= 0 && lx < N && ly >= 0 && ly < H * M && v[ly][lx] == 0) {
					q.push(make_pair(lx, ly));
					v[ly][lx]=1;
				}
			}
		}
		day++;
	}
	for (int y = 0; y < M * H; y++) {
		for (int x = 0; x < N; x++) {
			if (v[y][x] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << day-1;
	return 0;
}