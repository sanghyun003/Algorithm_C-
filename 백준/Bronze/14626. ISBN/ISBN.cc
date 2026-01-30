#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	int total=0, temp, check;
	int list[13];

	cin >> input;
	for (int i = 0; i < 13; i++) {
		list[i] = input[i] - '0';
	}
	check = list[12];

	for (int i = 0; i < 12; i++) {
		if (input[i] != '*') {
			total += list[i] * (3 - 2 * ((i + 1) % 2));
		}
		else {
			temp = 3 - 2 * ((i + 1) % 2);
		}
	}

	for (int i = 0; i < 10; i++) {
		int total_d = (10 - (total + i * temp) % 10)%10;
		if (total_d == check) {
			cout << i;
			break;
		}
	}

	return 0;
}