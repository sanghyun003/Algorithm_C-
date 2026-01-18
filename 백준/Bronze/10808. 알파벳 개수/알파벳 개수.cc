#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int list[26] = { 0 };
    string input;

    cin >> input;
    
    for (const char& c : input) {
        list[c - 'a']++;
    }
    for (int cnt : list) {
        cout << cnt << " ";
    }

    return 0;
}