#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	int wall=0, oneside=0, all=0, vac=0, s=0,e=0;
	string st;
	char c;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> st;
		stringstream ss(st);
		while (ss >> c) {
			if (c == '#') wall++;
			else if (c == 'U' || c == 'D' || c == 'L' || c == 'R') oneside++;
			else if (c == 'A') all++;
			else if (c == 'V') vac++;
			else if (c == 'S')s++;
			else if (c == 'E')e++;
		}
	}
	if (s != 1 || e != 1) cout << -1;
	else if (wall <= 1 && all == 0 && oneside <= 1 && vac == 0) cout << 1;
	else if (all == 0 && vac == 0) cout << 2;
	else if (all == 0) cout << 3;
	else cout << 4;
}