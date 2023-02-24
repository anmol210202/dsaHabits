class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> p;
        for(auto &e:nums) {if(e%2==1) e*=2; p.push(e);}
        int minValue=*min_element(nums.begin(),nums.end()),ans=INT_MAX;
        while(true){
            int maxValue=p.top();
            p.pop();
            ans=min(ans,maxValue-minValue);
            if(maxValue%2==1) break;
            maxValue/=2;
            minValue=min(minValue,maxValue);
            p.push(maxValue);
        }
        return ans;
    }
};
