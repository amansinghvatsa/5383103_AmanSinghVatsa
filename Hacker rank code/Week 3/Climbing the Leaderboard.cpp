#include <iostream>
#include <vector>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    // Remove duplicates from ranked
    vector<int> uniqueRanked;
    uniqueRanked.push_back(ranked[0]);
    for (int i = 1; i < ranked.size(); i++) {
        if (ranked[i] != ranked[i - 1]) {
            uniqueRanked.push_back(ranked[i]);
        }
    }
    
    int n = uniqueRanked.size();
    vector<int> result;
    int idx = n - 1;  // start from lowest score
    
    for (int score : player) {
        while (idx >= 0 && score >= uniqueRanked[idx]) {
            idx--;
        }
        result.push_back(idx + 2); 
        // idx+1 would give rank, but +1 more since idx decreased beyond position
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> ranked(n);
    for (int i = 0; i < n; i++) cin >> ranked[i];

    int m;
    cin >> m;
    vector<int> player(m);
    for (int i = 0; i < m; i++) cin >> player[i];

    vector<int> ans = climbingLeaderboard(ranked, player);
    for (int r : ans) cout << r << "\n";
    return 0;
}
