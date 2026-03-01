#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	int cnt=1;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	cin >> n >> m;

	vector<vector<int>> v(1000,vector<int>(1000));
	vector<vector<int>> answer(1000,vector<int>(1000));
	queue<pair<int, int>> q;
	int q_cnt = 1;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> v[y][x];
			if (v[y][x] == 2) {
				q.push(make_pair(x, y));
				answer[y][x] = 0;
				v[y][x] = 0;
			}
		}
	}

	while (!q.empty()) {
		q_cnt = q.size();
		while (q_cnt--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int lx = x + dx[i];
				int ly = y + dy[i];
				if (lx >= 0 && lx < m && ly >= 0 && ly < n && v[ly][lx] == 1) {
					q.push(make_pair(lx, ly));
					answer[ly][lx] = cnt;
					v[ly][lx] = 0;
				}
			}
		}
		cnt++;
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (v[y][x] == 1) {
				answer[y][x] = -1;
			}
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cout << answer[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
