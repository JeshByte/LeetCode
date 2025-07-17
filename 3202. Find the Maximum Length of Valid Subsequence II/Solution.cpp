class Solution {
public:
    
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k,vector<int>(k,0));
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int req=nums[i]%k;
            for(int j=0;j<k;j++){
                dp[j][req]=dp[req][j]+1;
                ans=max(ans,dp[j][req]);
            }
        }
        return ans;
    }
};
