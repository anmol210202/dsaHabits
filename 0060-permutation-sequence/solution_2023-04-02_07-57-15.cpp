class Solution {
public:
    string getPermutation(int n, int k) {
        // Calculate factorials
        vector<int> fact(n, 1);
        for (int i = 1; i < n; i++) {
            fact[i] = i * fact[i-1];
        }
        
        // Initialize set of digits
        vector<int> digits(n);
        for (int i = 0; i < n; i++) {
            digits[i] = i+1;
        }
        
        // Calculate kth permutation
        string result;
        k--; // 0-based indexing
        for (int i = n-1; i >= 0; i--) {
            int index = k / fact[i];
            result += to_string(digits[index]);
            digits.erase(digits.begin() + index);
            k %= fact[i];
        }
        return result;
    }
};
