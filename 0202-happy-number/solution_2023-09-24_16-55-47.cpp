class Solution {
public:

    int nextNum(int n){
        int newNum = 0;
        while(n!=0){
            int num = n%10;
            newNum += num*num;
            n/=10;

        }
        return newNum;
    }

    bool isHappy(int n) {
        unordered_set<int> us;
        while(n!=1 and !us.count(n)){
            us.insert(n);
            n=nextNum(n);
        }
        return n==1;
    }
};
