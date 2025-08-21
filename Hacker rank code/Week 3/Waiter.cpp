#include <iostream>
#include <vector>
using namespace std;

// Function to generate first q primes
vector<int> generatePrimes(int q) {
    vector<int> primes;
    int num = 2;
    while ((int)primes.size() < q) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(num);
        num++;
    }
    return primes;
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> result;
    vector<int> primes = generatePrimes(q);

    vector<int> A0 = number; // initial stack (bottom to top as given)
    
    for (int i = 0; i < q; i++) {
        vector<int> A1, B;
        int p = primes[i];
        
        // Process from top to bottom
        for (int j = A0.size() - 1; j >= 0; j--) {
            if (A0[j] % p == 0)
                B.push_back(A0[j]);
            else
                A1.push_back(A0[j]);
        }
        
        // Push B (top to bottom) to result
        for (int j = B.size() - 1; j >= 0; j--) {
            result.push_back(B[j]);
        }
        
        // Prepare for next iteration
        A0 = A1;
    }
    
    // After all q iterations, push remaining A0
    for (int j = A0.size() - 1; j >= 0; j--) {
        result.push_back(A0[j]);
    }
    
    return result;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> number(n);
    for (int i = 0; i < n; i++) cin >> number[i];
    
    vector<int> ans = waiter(number, q);
    
    for (int x : ans) cout << x << "\n";
    
    return 0;
}
