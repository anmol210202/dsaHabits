class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int s=arr.size() , a=0;
        for(int i=0; i<s; i++){
            a+=(arr[i]*ceil((i+1)*(s-i)/2.0));
        }
        return a;
    }
};
