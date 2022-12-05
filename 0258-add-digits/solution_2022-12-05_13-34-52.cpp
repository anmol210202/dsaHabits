class Solution {
public:
    int ld(int n){
        int sum =0;
        while(n>0){
            int x = n%10;
            sum+=x;
            n/=10;
        }
        return sum;
    }
    
    int addDigits(int num) {
        if(num <10) return num;
        int q = ld(num);
        while(q>=10){
            q = ld(q);
        }
        return q;
    }
};
