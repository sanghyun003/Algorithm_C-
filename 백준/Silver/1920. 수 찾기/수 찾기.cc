#include<iostream>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, num;
	int list[100000];
	set<long> s;

	cin >> N;
	while (N-- > 0) {
		cin >> num;
		s.insert(num);
	}

	cin >> M;
	for (int i = 0; i < M;i++) {
		cin >> num;
		(s.find(num) != s.end()) ? list[i] = 1 : list[i]=0;
	}
	for (int i = 0; i < M; i++) {
		cout << list[i] << '\n';
	}
	return 0;
}