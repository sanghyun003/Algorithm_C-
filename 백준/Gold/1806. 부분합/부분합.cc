#include <iostream>

using namespace std;

int main() {
	int N, S, num, temp, answer=100000;
	long long list[100001] = { 0 };
	int left=0, right=0;
	bool check=false;

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> num;
		list[i] = num;
	}
	temp = list[0];
	while (right < N) {
		if (temp < S) {
			temp+= list[++right];
		}
		if (temp >= S) {
			answer = min(answer,right - left+1);
			temp -= list[left++];
			check = true;
		}
	}

	if (check == true)
		cout << answer;
	else
		cout << 0;

	return 0;
}