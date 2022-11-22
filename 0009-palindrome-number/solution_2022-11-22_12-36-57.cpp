class Solution {
public:
    
    int reverse(int x){
        int rev = 0;
        while(x > 0){
            int pop = x % 10;
            x /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return false;
            if(rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return false;
            rev = rev * 10 + pop;
        }
        return rev;
    }
    
    bool isPalindrome(int x) {
        return x >= 0 && x == reverse(x);
    }
};
