class Solution {
public:
    bool check(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
    int diagonalPrime(vector<vector<int>>& nums) {
        int mx=0, m=nums.size(), n= nums[0].size(),i=0,j=0;
        while(i<m and j<n) {
            if(check(nums[i][j])) {
                mx=max(mx,nums[i][j]);
            }
            i++,j++;
        }
        i=0,j=n-1;
        while(i<m and j>=0) {
            if(check(nums[i][j])) {
                mx=max(mx,nums[i][j]);
            }
            i++,j--;
        }
        return mx;
    }
};
