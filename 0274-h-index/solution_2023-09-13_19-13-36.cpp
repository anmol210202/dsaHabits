class Solution {
public:
    
    static bool cmp(int a , int b){
        return a>b;
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),cmp);
        int hIndex=0, n=citations.size();
        for(auto &e:citations){
            if(e>hIndex) hIndex++;
            else return hIndex;
        }
        return hIndex;
    }
};
