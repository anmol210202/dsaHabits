class Solution {
public:
    bool check(string &s,int l){
        if(int(tolower(s[l]))>=97 and int(tolower(s[l]))<=122 || int(tolower(s[l]))>=48 and int(tolower(s[l]))<=57) return true;
        return false;
    }
    bool isPalindrome(string &s) {
        int l=0 , r=s.size()-1;
        while(l<=r)
            if(check(s,l) and check(s,r))
                if(tolower(s[l])!=tolower(s[r])) return false;
                else{
                    l++; r--;
                }
            else if(check(s,l) and !check(s,r)) r--;
            else if(!check(s,l)and check(s,r)) l++;
            else{
                l++; r--;
            }
        return true;
    }
};
