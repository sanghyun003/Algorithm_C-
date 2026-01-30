#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, num;
	int list[10001] = { 0 };

	cin >> N;

	for(int i=0;i<N;i++) {
		cin >> num;
		list[num]++;
	}

	for (int i=0; i < 10001;i++) {
		for (int j = 0; j<list[i]; j++) {
			cout << i << '\n';
		}
	}

	return 0;
}