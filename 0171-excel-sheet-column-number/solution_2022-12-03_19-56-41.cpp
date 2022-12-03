class Solution {
public:
    int titleToNumber(string columnTitle) {
        int x=0;
        for(auto &e:columnTitle){
            x*=26;
            x+=e - 'A'+1;
        }
        return x;
    }
};
