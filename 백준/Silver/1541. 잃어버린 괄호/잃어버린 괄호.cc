#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num=0, answer =0,op=1;
	string s;
	vector<int> v;

	cin >> s;

	for (char c : s) {
		if (c != '-'&&c!='+') {
			num = 10 * num + (c - '0');
		}
		else{
			if (op==-1) num *= -1;
			v.push_back(num);
			num = 0;
			if (c == '-') op = -1;
		}
	}
	if (op == -1) num *= -1;
	v.push_back(num);

	for (int i : v) {
		answer += i;
	}

	cout << answer;

	return 0;
}