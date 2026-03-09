#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int num, answer=0;
	int left=0, right=0;
	map<int,int> m;

	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	if (N == 1) {
		cout << 1;
		return 0;
	}

	m[v[left]]++;
	while (right < N) {
		int m_size = 0;
		for (int i = 1; i <= 9; i++) {
			if (m[i] > 0) m_size++;
		}
		if (m_size <= 2) {
			answer = max(answer, right - left + 1);
			if (++right < N)
				m[v[right]]++;
			else break;
		}
		else {
			m[v[left++]]--;
		}
	}

	cout << answer;

	return 0;
}