class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        while(columnNumber>0){
            columnNumber--;
            int k = columnNumber%26;
            s+=k+'A';
            columnNumber/=26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
