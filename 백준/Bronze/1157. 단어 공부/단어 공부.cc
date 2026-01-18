#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int list[26]={0,}, m = 0;
    string s;
    char answer=0;
    int num;

    cin >> s;
    for (char c : s) {
        num = toupper(c) - 65;
        list[num]++;
    }
    for (int i=0 ;i<26;i++) {
        if (list[i] > m) {
            m = list[i];
            answer = i + 65;
        }
        else if (list[i] == m) answer = '?';
    }

    cout << answer;

    return 0;
}