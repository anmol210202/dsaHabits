class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX , profit = 0; 
        for(auto &e:prices ) mn = min(mn , e) , profit = max(profit , e-mn);
        return profit;
    }
};
