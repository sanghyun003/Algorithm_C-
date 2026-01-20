#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, cnt=0;
	string name;
	map<string, int> m;

	cin >> N >> M;
	while (N-- > 0) {
		cin >> name;
		m[name]++;
	}
	while (M-- > 0) {
		cin >> name;
		m[name]++;
		if (m[name] == 2) cnt++;
	}

	cout << cnt << '\n';

	for (auto& c : m) {
		if(c.second==2)
			cout << c.first<<'\n';
	}
	return 0;
}