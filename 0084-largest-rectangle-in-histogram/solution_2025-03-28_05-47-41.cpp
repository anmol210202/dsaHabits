class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n=heights.size();
        int ans =0;
        s.push(-1);
        
        for(int i=0; i<n; i++){
            while(s.top() != -1 && heights[s.top()]>heights[i]){
                int height = heights[s.top()];
                s.pop();
                int width = i-s.top()-1;
                ans = max(ans,height*width);
            }
            s.push(i);
        }

        while(s.top() != -1){
            int height = heights[s.top()];
            s.pop();
            int width = n-s.top()-1;
            ans = max(ans,height*width);
        }
        return ans;
    }
};
