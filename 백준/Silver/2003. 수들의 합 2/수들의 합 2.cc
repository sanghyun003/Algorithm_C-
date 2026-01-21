#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int list[10000];
	int N, M, num;
	int answer = 0;

	cin >> N >> M;

	for (int i = 0; i < N;i++) {
		cin >> num;
		list[i] = num;
	}
	for (int i = 0; i < N; i++) {
		int s = list[i];
		if (s == M) {
			answer++;
		}
		else {
			for (int j = i + 1; j < N; j++) {
				s += list[j];
				if (s == M) {
					answer++;
					break;
				}
			}
		}
	}

	cout << answer;

	return 0;
}