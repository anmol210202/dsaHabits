class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for(int i=size-1; i>=0; i--){
            if(digits[i]!=9){
                digits[i]++;
                break;
            } else{
                if(i!=0){
                    digits[i]=0;
                } else{
                    digits[i]=0;
                    digits.push_back(1);
                    rotate(digits.rbegin(), digits.rbegin() + 1, digits.rend());
                    break;
                }
            }
        }
        return digits;
    }
};
