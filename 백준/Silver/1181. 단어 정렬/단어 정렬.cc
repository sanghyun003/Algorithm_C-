#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool cmp(string& a, string& b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;
	set<string> set;
	string st;

	for (int i = 0; i < N; i++) {
		cin >> st;
		set.insert(st);
	}
	vector<string> v (set.begin(), set.end());

	sort(v.begin(), v.end(),cmp);

	for (string s : v) {
		cout << s << '\n';
	}

	return 0;
}