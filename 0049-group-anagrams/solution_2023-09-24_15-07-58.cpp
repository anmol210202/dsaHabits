class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> um;
        for(auto &e:strs){
            string sortStr = e;
            sort(sortStr.begin(),sortStr.end());
            um[sortStr].push_back(e);
        }

        vector<vector<string>> ans;
        for(auto &e:um){
            ans.push_back(e.second);
        }
        return ans;
    }
};
