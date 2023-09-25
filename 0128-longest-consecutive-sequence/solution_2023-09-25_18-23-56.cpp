class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int a=0;
        for(auto &e:s){
            int c=0;
            if(s.find(e-1)==s.end()){
                c=1;
                while(s.find(e+c)!=s.end()) c++;
                a=max(a,c);
            }
        }
        return a;
    }
};
