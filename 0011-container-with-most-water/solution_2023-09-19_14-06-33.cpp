class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=0, i=0 , j=height.size()-1;
        while(i<j){
            int area = min(height[i],height[j])*(j-i);
            mx=max(mx,area);
            if(height[i]>height[j]) j--;
            else i++;
        }

        return mx;
    }
};
