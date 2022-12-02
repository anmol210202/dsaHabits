class Solution {
public:
    int mySqrt(int x) {
        long long l=0 , r=x;
        while(l<r){
            long long m = l + (r-l+1)/2;
            if(m*m>x) r = m-1;
            else l = m;
        }
        return l;
    }
};
