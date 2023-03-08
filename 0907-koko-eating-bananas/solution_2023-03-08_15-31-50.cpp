class Solution {
public:
    bool check(int m,vector<int> &piles,int h){
        int c=0;
        for(auto &e:piles){
            if(e<=m) c++;
            else c+=(e%m==0) ? e/m:(e/m)+1;
            if(c>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=*max_element(piles.begin(),piles.end()),m=s+(e-s)/2,a=0;
        while(s<=e){
            if(check(m,piles,h)) a=m,e=--m;
            else s=++m;
            m=s+(e-s)/2;
        }
        return a;
    }
};
