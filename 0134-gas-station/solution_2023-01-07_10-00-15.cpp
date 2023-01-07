class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> v;
        for(int i=0; i<gas.size(); i++) v.push_back(gas[i]-cost[i]);
        int sum=0 ,a=0,temp=0;
        for(int i=0; i<v.size(); i++){
            sum+=v[i];
            temp+=v[i];
            if(temp<0){
                a=i+1;
                temp=0;
            }
        }
        return (sum<0) ? -1:a;
    }
};
