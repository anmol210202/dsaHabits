class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = 0 , c = 0 , n=nums.size();
        for(auto &e:nums){
            if(c == 0 ) can = e, c++;
            else if( can == e) c++;
            else c--;
        }
        c=0;
        for(auto &e:nums){
            if(can==e) c++;
            if(n/2<c) return can ;
        }
        return -1;
    }
};
