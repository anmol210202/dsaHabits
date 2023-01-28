class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> v;
        for(int i=0; i<number.size(); i++) if(number[i]==digit){
            number.erase(number.begin()+i);
            v.push_back(number);
            number.insert(number.begin()+i,digit);
        }
        return *max_element(v.begin(),v.end());
    }
};
