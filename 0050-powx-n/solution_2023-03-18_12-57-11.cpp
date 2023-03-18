class Solution {
public:
    double myPow(double x, int n) {
        long N=(long)n;
        if(N==0) return 1;
        if(N<0) x=1/x,N*=-1;
        double a = myPow(x,N/2);
        if(N&1) return a*a*x;
        else return a*a;
    }
};
