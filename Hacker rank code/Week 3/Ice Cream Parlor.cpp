#include <iostream>
#include <vector>
using namespace std;

vector<int> icecreamParlor(int m, vector<int>& cost) {
    unordered_map<int, int> mp; // cost -> index
    
    for (int i = 0; i < cost.size(); i++) {
        int needed = m - cost[i];
        
        if (mp.find(needed) != mp.end()) {
            // Found the pair
            return {mp[needed] + 1, i + 1}; // +1 for 1-based indexing
        }
        
        mp[cost[i]] = i;
    }
    return {}; // should never reach (unique solution always exists)
}

int main() {
    int t; 
    cin >> t;  // number of trips
    
    while (t--) {
        int m, n;
        cin >> m >> n; // money, number of flavors
        vector<int> cost(n);
        for (int i = 0; i < n; i++) cin >> cost[i];
        
        vector<int> ans = icecreamParlor(m, cost);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    
    return 0;
}
