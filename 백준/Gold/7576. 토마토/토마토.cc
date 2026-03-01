#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N;
	int num;
	int answer = 0;
	int cnt = 0;

	queue<pair<int,int>> q;
	int q_cnt = 0;

	vector<vector<int>> v(1000,vector<int>(1000));

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	cin >> M >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> v[y][x];
			if (v[y][x] == 0) cnt++;
			if (v[y][x] == 1) {
				q_cnt++;
				q.push(make_pair(x, y));
			}
		}
	}
	if (cnt == 0) {
		cout << 0;
		return 0;
	}
	while (!q.empty()) {
		q_cnt = q.size();
		while (q_cnt--) {
			int x = q.front().first;
			int y = q.front().second;

			for (int i = 0; i < 4; i++) {
				int lx = x + dx[i];
				int ly = y + dy[i];
				if (lx >= 0 && lx < M && ly >= 0 && ly < N
					&& v[ly][lx] == 0) {
					q.push(make_pair(lx, ly));
					v[ly][lx] = 1;
				}
			}
			q.pop();
		}
		answer++;
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (v[y][x] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << answer-1;
	return 0;
}