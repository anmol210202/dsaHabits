class Solution {
public:
    
    static bool cmp(int a , int b){
        return a>b;
    }
    int hIndex(vector<int>& citations) {
        // sorting app

        // sort(citations.begin(),citations.end(),cmp);
        int hIndex=0, n=citations.size();
        // for(auto &e:citations){
        //     if(e>hIndex) hIndex++;
        //     else return hIndex;
        // }
        // return hIndex;

        // counting sort app

        vector<int> v(n+1,0);

        for(auto &e:citations){
            if(e>=n) v[n]++;
            else v[e]++;
        }

        for(int i=n ; i>=0; i--){
            hIndex +=v[i];
            if(hIndex >= i) return i;
        }
        return 0;
    }
};
