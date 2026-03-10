#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n;

	cin >> T;

	for (int i = 0; i < T; i++) {
		deque<int> dq;
		string p, s;
		int num = 0;
		bool check = false;
		bool error = false;

		cin >> p;
		cin >> n;
		cin >> s;

		for (char c : s) {
			if (c - '0' >= 0 && c - '0' <= 9) {
				num = num * 10 + (c - '0');
			}
			else if (num>0&&(c == ',' || c==']')) {
				dq.push_back(num);
				num = 0;
			}
		}

		for (char c : p) {
			if (c == 'R')check = !check;
			else {
				//정방향이면
				if (dq.empty()) {
					error = true;
					break;
				}
				else if (check == false) {
					dq.pop_front();
				}
				//역방향이면
				else {
					dq.pop_back();
				}
			}
		}
		if (error) {
			cout << "error"<<'\n';
		}
		else {
			cout << '[';
		if (check == false) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i < dq.size() - 1) cout << ',';
				}
			}
			else {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[dq.size()-1-i];
					if (i < dq.size() - 1) cout << ',';
				}
			}
			cout << ']'<<'\n';
		}
	}
	return 0;
}