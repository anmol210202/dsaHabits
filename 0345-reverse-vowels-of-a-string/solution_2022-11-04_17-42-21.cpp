class Solution {
public:
    string reverseVowels(string s) {
        int x = s.size();
        set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
        int l=0 , r= x-1;
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(l<r){
            while(l<r and !v.count(s[l])) l++; 
            while(l<r and !v.count(s[r])) r--; 
            swap(s[l++],s[r--]);
        }
        return s;
    }
};
