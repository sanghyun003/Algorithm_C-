#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, answer = 0, hap = 0;

	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < N; i++) {
		hap += v[i];
		answer += hap;
	}

	cout << answer;

	return 0;
}