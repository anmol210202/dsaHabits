class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = height.size();
        int ans=0 , i=0 , j=s-1;
        while(i<j){
            ans=max(ans,(j-i)*((height[i]>=height[j])? height[j]:height[i]));
            // cout<<(j-i)*((height[i]>=height[j])? height[j]:height[i])<<endl;
            if(height[i]>=height[j]) j--;
            // if else(height[i]==height[j]) (height[i+1]>=height[j-1] ? )
            else i++;
        }
        return ans;
    }
};
