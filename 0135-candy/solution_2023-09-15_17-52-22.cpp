class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        vector<int> can(n,1);

        // left to right 
        for(int i=1 ; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                can[i]=can[i-1]+1;
            }
        }

        // right to left 
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1] and can[i]<=can[i+1]){
                can[i]=can[i+1]+1;
            }
        }

        // accumulate 
        return accumulate(can.begin(), can.end(), 0);
    }
};
