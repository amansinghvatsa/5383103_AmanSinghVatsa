#include <iostream>
#include <vector>
#include <string>
using namespace std;

string isValid(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    unordered_map<int, int> freqCount;
    for (auto &p : freq) {
        freqCount[p.second]++;
    }

    if (freqCount.size() == 1) {
        return "YES";
    }

    if (freqCount.size() == 2) {
        auto it = freqCount.begin();
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;

        // Case 1: One frequency occurs once and is 1 (e.g., aabbc -> c only once)
        if ((c1 == 1 && f1 == 1) || (c2 == 1 && f2 == 1)) {
            return "YES";
        }

        // Case 2: One frequency occurs once and differs by exactly 1
        if ((c1 == 1 && abs(f1 - f2) == 1) || (c2 == 1 && abs(f1 - f2) == 1)) {
            return "YES";
        }
    }

    return "NO";
}

int main() {
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}
