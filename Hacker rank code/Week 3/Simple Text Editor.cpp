#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    string s = "";
    stack<string> history; // stack to store states for undo

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // append
            string w;
            cin >> w;
            history.push(s);
            s += w;
        } else if (type == 2) {
            // delete
            int k;
            cin >> k;
            history.push(s);
            s.erase(s.size() - k);
        } else if (type == 3) {
            // print
            int k;
            cin >> k;
            cout << s[k - 1] << "\n";
        } else if (type == 4) {
            // undo
            if (!history.empty()) {
                s = history.top();
                history.pop();
            }
        }
    }
    return 0;
}
