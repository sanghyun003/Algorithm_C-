#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int this_map[25][25];
bool visited[25][25];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int h_cnt = 0;

//집의 수를 count하며 재귀하는 dfs, 아직 방문하지 않고 집이 있는 곳을 상하좌우로만 탐색
void dfs(int x, int y, int N) {
	visited[y][x] = true;
	h_cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[ny][nx] == false && this_map[ny][nx]==1) {
			dfs(nx, ny, N);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	string s;
	vector<int> answer;

	cin >> N;

	//입력을 string으로 받아 char형으로 꺼내 정수형으로 this_map에 넣어주기
	for (int y = 0; y < N; y++) {
		cin >> s;
		for (int x = 0; x < N; x++) {
			this_map[y][x] = s[x] - '0';
		}
	}

	//this_map의 모든 좌표를 순회하며 아직 방문하지 않았고 단지가 있는 곳이면 dfs 진행
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == false && this_map[y][x] == 1) {
				h_cnt = 0;
				dfs(x, y, N);
				answer.push_back(h_cnt); // 집의 수를 answer에 삽입
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}