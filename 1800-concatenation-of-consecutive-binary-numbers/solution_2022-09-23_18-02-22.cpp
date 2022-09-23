class Solution {
public:
    string c(long long  n) {
      string s1="";
        
      while(n) {
        s1 += (n%2) + '0';
        n /= 2;
      }
       // reverse(s1.begin(),s1.end()); 
        return s1;
    }

            long long pow=1;

    
    long long x(long long n,long long a,long long s) {
        if(n==0) return s;
        
        string s1 = c(n);
        // string s1=decimalToBinary(n);
        
        // long long v=(int)(log2(n));
        // string s1=bitset<64>(n).to_string().substr(64 - v- 1);
        
        
        long long sum=0;
        
        
        for(long long i=0; i<s1.size(); i++) {
            if(s1[i]=='1') {
                sum=(sum+pow)%1000000007;
                a++;
            } else {a++;}
            pow=(pow*2)%1000000007;
        }
        s+=sum;
        return x(n-1,a,s);
    }
    
    int concatenatedBinary(int n) {
        return x(n,0,0)%1000000007;
    }
};
