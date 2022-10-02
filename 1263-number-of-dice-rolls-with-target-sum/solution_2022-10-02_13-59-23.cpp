class Solution {
public:
 int count(int n,int k ,int target,vector<vector<long long>> &v) {
        if(n==0) return (target ==0) ? 1:0;
        if(target<0 || n>target || k*n<target) return 0;
        
        
            if(v[n][target]==0){
                for(int i=1; i<=k; i++){
                (v[n][target])+=(count(n-1,k,target-i,v))%1000000007;
            }
        }
        return v[n][target]%1000000007;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> v(31,vector<long long>(1001));
        return count(n,k,target,v);
    }
};
