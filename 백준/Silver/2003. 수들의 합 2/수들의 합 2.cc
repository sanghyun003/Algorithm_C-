#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int left=0;
    int right=0;
    int num, N, M, sum=0, answer=0;
    int list[10000] = { 0, };

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> num;
        list[i] = num;
    }
    sum = list[0];
    while (right <= N) {
        if (sum < M) {
            right++;
            sum += list[right];
        }
        else if (sum == M) {
            sum -= list[left];
            left++;
            answer++;
            
        }
        else {
            sum -= list[left];
            left++;
        }
    }

    cout << answer;

    return 0;
}