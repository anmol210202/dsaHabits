class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX;
        int ans = 0;
        for(int i=0; i<prices.size(); i++){
            mi = min(mi,prices[i]);
            if(prices[i]-mi>ans) ans = prices[i]-mi;
        }
        return ans;
    }
};
