class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(auto &e:s){
            e=tolower(e);
            if(int(e)>=97 and int(e)<=122 || int(e)>=48 and int(e)<=57) s1+=e;
        }
        int l=0 , r=s1.size()-1;
        while(l<=r)
            if(s1[l]!=s1[r]) return false;
            else{
                l++; r--;
            }
        return true;
    }
};
