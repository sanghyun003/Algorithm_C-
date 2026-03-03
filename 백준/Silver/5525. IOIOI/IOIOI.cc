#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M,cnt=0;
	int answer = 0;
	string s, s2;
	char tmp='O';
	vector<int>v;

	cin >> N >> M >> s;

	for (int i = 0; i < M; i++) {
		if (s[i] != tmp) {
			if (tmp == 'I'&&s2.empty()) s2.append(1,tmp);
			s2.append(1, s[i]);
		}
		else if(!s2.empty()){
			v.push_back(s2.size() - (s2.back() == 'O'));
			s2.clear();
		}
		tmp = s[i];
	}
	if (!s2.empty()) {
		v.push_back(s2.size()-(s2.back() == 'O'));
	}

	for (int c : v) {
		if (c >= 2 * N + 1) answer += c / 2 - N + 1;
	}
	cout << answer;

	return 0;
}