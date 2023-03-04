class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num),x,y;
        sort(s.begin(),s.end());
        for(auto i=0; i<s.size(); i++)
            if(i%2==0) x+=s[i];
            else y+=s[i];
        return stoi(x)+stoi(y);
    }
};
