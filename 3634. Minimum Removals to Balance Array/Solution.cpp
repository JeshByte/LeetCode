class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            long long t=nums[i]*(long long)k;
            auto it=upper_bound(nums.begin()+i,nums.end(),t);
            int j=(it-nums.begin())-1;
            if(j>=i){
                ans=max(ans,j-i+1);
            }
        }
        return n-ans;
    }
};
