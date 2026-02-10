#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, B, height, max_height=0, answer_time=0, answer_height=0;
	vector<vector<int>> v(500,vector<int>(500));
	bool first = true;

	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> height;
			v[i][j]=height;
			max_height = max(max_height, height);
		}
	}
	for (int i = 0; i <= max_height; i++) {
		int time = 0;
		int B1 = B;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				int temp = v[y][x] - i;
				if (temp >= 0) {
					time += temp * 2;
					B1 += temp;
				}
				else {
					time += -1 * temp;
					B1 -= -1*temp;
				}
			}
		}
		if (first) {
			answer_time = time;
			first = false;
		}
		if (B1 < 0) continue;
		if (answer_time >= time) {
			answer_time = time;
			answer_height = i;
		}

	}
	cout << answer_time << " " << answer_height;


	return 0;
}