class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int a=0;
        for(auto &e:costs){
            coins-=e;
            if(coins<0) return a;
            a++;
        }
        return a;
    }
};
