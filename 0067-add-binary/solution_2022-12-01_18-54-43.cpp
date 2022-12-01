class Solution {
public:
    string addBinary(string a, string b) {
        int x = a.size()-1 , y = b.size()-1, c=0;
        string ans;
        while(x>=0 or y>=0 or c){
            if(x>=0){
                c += a[x] - '0';
                x--;
            }
            if(y>=0){
                c += b[y] - '0';
                y--;
            }
            ans += c%2+'0';
            c/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
