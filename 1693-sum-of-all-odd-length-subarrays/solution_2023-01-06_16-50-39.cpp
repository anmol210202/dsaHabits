class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int s=arr.size() , a=0,temp=0;
        for(int i=0; i<s; i++){
            temp = 0;
            for(int j=i;j<s; j++){
                temp+=arr[j];
                if((i+j)%2==0) a+=temp;
            }
        }
        return a;
    }
};
