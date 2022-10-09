class Solution {
public:
    int reverse(int x) {
        int num=abs(x);
        long ans = 0;
      while(num>0){
            int temp = num%10;
            ans = ans*10 + temp;
            num= num/10;
        }
        ans = ans*((x>0) ? 1:-1);
        if(ans<=INT_MAX and ans>=INT_MIN) return ans;
        else return 0;
    }
};
