#include <bits/stdc++.h>
using namespace std;

string balancedSums(vector<int> arr) {
    long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);
    long long leftSum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        long long rightSum = totalSum - leftSum - arr[i];
        if (leftSum == rightSum) {
            return "YES";
        }
        leftSum += arr[i];
    }
    return "NO";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << balancedSums(arr) << endl;
    }
    return 0;
}
