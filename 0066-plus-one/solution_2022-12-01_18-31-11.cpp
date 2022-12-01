class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--){
            if(digits[i]!=9){
                digits[i]++;
                break;
            } else{
                if(i!=0){
                    digits[i]=0;
                } else{
                    digits[i]=0;
                    digits.insert(digits.begin(),1);
                    break;
                }
            }
        }
        return digits;
    }
};
