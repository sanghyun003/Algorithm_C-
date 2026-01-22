#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, num; 
	long long total = 0, t_max = 0;
	int list[100000] = { 0, };

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num;
		list[i] = num;
	}

	for (int i = 0; i < m; i++) {
		total += list[i];
	}
	t_max = total;

	for (int i = m; i < n; i++) {
		total += list[i];
		total -= list[i - m];
		t_max = max(t_max, total);
	}

	cout << t_max;

	return 0;
}