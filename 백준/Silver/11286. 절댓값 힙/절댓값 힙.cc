#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, N;
	priority_queue<pair<int, int>, vector<pair<int,int>>,cmp> pq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if(x!=0)
			pq.push(make_pair(abs(x), x));
		else {
			if (!pq.empty()) {
				auto p = pq.top();
				pq.pop();
				cout << p.second<<'\n';
			}
			else cout << 0 << '\n';
		}
	}
	return 0;
}