#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; i++)
        cin >> board[i];

    int answer = 64;

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int cntB = 0, cntW = 0;

            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    char cur = board[i + x][j + y];

                    if ((x + y) % 2 == 0) {
                        if (cur != 'B') cntB++;
                        if (cur != 'W') cntW++;
                    } else {
                        if (cur != 'W') cntB++;
                        if (cur != 'B') cntW++;
                    }
                }
            }
            answer = min(answer, min(cntB, cntW));
        }
    }

    cout << answer;
}
