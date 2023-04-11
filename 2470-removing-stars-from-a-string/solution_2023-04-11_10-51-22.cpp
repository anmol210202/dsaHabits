class Solution {
public:
    string removeStars(string s) {
        stack<char> sta;
        for(auto &e:s){
            if(e=='*' and !sta.empty()) sta.pop();
            else sta.push(e);
        }
        s.clear();
        while(!sta.empty()){
            s+=sta.top();
            sta.pop();
        }
        reverse(s.begin(),s.end());
        return s; 
    }
};
