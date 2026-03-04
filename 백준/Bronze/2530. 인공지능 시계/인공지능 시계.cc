#include <iostream>

using namespace std;

int main() {
    int h, m, s;
    int input;

    cin >> h >> m >> s;
    cin >> input;

    h += input / 3600;
    m += input % 3600 / 60;
    s += input % 60;
    if (s >= 60) {
        s -= 60;
        m++;
    }
    if (m >= 60) {
        m -= 60;
        h++;
    }
    if (h >= 24) {
        h %= 24;
    }
    cout << h << ' ' << m << ' ' << s;
    return 0;
}