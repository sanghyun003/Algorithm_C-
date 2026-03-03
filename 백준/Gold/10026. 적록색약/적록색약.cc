#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void bfs(int start_x,int start_y, int N,vector<vector<int>>& v) {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int tmp = v[start_y][start_x];
	queue<pair<int,int>> q;
	q.push(make_pair(start_x,start_y));
	v[start_y][start_x] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int lx = x + dx[i];
			int ly = y + dy[i];
			if (ly >= 0 && ly < N && lx >= 0 && lx < N && v[ly][lx] == tmp) {
				q.push(make_pair(lx, ly));
				tmp = v[ly][lx];
				v[ly][lx] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	string s;
	int answer1 = 0, answer2 = 0;

	vector<vector<int>> v(100, vector<int>(100));

	cin >> N;

	for (int y = 0; y < N; y++) {
		cin >> s;
		int x = 0;
		for (char c : s) {
			if (c == 'R') v[y][x]=1;
			else if (c == 'G')v[y][x]=2;
			else if (c == 'B')v[y][x]=3;
			x++;
		}
	}
	vector<vector<int>> vc(v.begin(), v.end());

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (v[y][x] == 2) {
				vc[y][x] = 1;
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (v[y][x] != 0) {
				answer1++;
				bfs(x, y, N, v);
			}
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (vc[y][x] != 0) {
				answer2++;
				bfs(x, y, N,vc);
			}
		}
	}

	cout << answer1 << ' ' << answer2;

	return 0;
}