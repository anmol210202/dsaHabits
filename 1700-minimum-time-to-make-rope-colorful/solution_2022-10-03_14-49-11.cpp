class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int size = colors.length();
        vector<vector<int>> v;
        vector<int> temp;
        bool x=false;
        for(int i=0; i<size; i++){
            if(colors[i]==colors[i+1] and i!=size-1){
                temp.push_back(neededTime[i]);
                x=true;
            }else{
                if(x || (x and (i==size-2))){
                    temp.push_back(neededTime[i]);
                    v.push_back(temp);
                    temp.clear();
                    x=false;
                }
            }
        }
        int ans=0;
        for(auto e:v){
            ans+=accumulate(e.begin(), e.end(), 0)-*max_element(e.begin(), e.end());
            // int mx=*min_element(e.begin(), e.end());
        }
        return ans;
    }
};
