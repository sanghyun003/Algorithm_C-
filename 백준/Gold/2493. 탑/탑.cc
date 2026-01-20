#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, num;
	stack<pair<int,int>> s;
	vector<int> v;

	cin >> N;

	for (int i = 1; i <= N;i++) {
		cin >> num;
		
		while(!s.empty()&&num > s.top().first) {
			s.pop();
		}
		if (s.empty()) {
			s.push(make_pair(num, i));
			v.push_back(0);
		}
		else if (num < s.top().first) {
			v.push_back(s.top().second);
			s.push(make_pair(num, i));
		}
	}

	for (int c : v) {
		cout << c << ' ';
	}
	return 0;
}