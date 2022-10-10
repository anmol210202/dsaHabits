class Solution {
public:
    string breakPalindrome(string palindrome) {
        int s = palindrome.size();
        if(s==1) return "";
        for(int i=0; i<s/2; i++){
            if(palindrome[i]!='a') {
                palindrome[i]='a';
                break;
            } else if(i==(s/2)-1){
                palindrome[s-1]='b';
            }
        }
        return palindrome;
    }
};
