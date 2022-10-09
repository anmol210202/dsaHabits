class Solution {
public:
    vector<int> ans;  
int isPairSum(vector<int>A, int X)
{
    int N=A.size();
    int i = 0;
    int j = N - 1;
 
    while (i < j) {
        if (A[i] + A[j] == X){
             ans.push_back(i+1);
            ans.push_back(j+1);
            return 1;
        }
        else if (A[i] + A[j] < X)
            i++;
        else
            j--;
    }
    return 0;
}
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        isPairSum(numbers,target);
        return ans;
    }
};
