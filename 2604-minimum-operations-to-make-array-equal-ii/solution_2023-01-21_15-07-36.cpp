class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> d;
        long long s=0;
        if(nums1==nums2) return 0;
        else {
            if(k==0) return -1;
        }
        for(int i=0; i<nums1.size(); i++){
            if((nums1[i]-nums2[i])%k!=0) return -1;
            d.push_back(nums1[i]-nums2[i]);
            s+=nums1[i]-nums2[i];
        }
        if(s!=0) return -1;
        sort(d.begin(),d.end());
        long long i=0, j=d.size()-1,ans=0;;
        // for(auto &e:d) cout<<e<<" ";
        // cout<<endl;
        while(i<j){
            if(d[i]+d[j]==0){
                ans+=abs(d[i]/k);
                d[i]=0;
                d[j]=0;
                i++;
                j--;
            }
            else if(d[i]+d[j]<0){
                ans+=abs(d[j]/k);
                d[i]+=d[j];
                d[j]=0;
                j--;
            }
            else {
                ans+=abs(d[i]/k);
                d[j]+=d[i];
                d[i]=0;
                i++;
            }
        }
        // for(auto &e:d) cout<<e<<" ";
        return ans;
    }
};
