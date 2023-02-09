class Solution {
public:
    int bitwiseComplement(int n) {
        int mask=0,m=n;
        if(n==0) return 1;
        while(m!=0){
            m>>=1;
            mask<<=1;
            mask|=1;
        }
        return ~n&mask;
    }
};
