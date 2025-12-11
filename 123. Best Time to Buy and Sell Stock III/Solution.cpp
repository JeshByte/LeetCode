class Solution {
public:
    int solve(vector<int>& prices,int n,vector<vector<vector<int>>>& dp){
        dp[n-1][0][0]=prices[n-1];
        dp[n-1][0][1]=0;
        dp[n-1][1][0]=prices[n-1];
        dp[n-1][1][1]=0;
        dp[n-1][2][0]=dp[n-1][2][1]=0;
        for(int i=n-2;i>=0;i--){
            for(int cnt=2;cnt>=0;cnt--){
                if(cnt<=1){
                    dp[i][cnt][1]=max(-prices[i]+dp[i+1][cnt][0],dp[i+1][cnt][1]);
                    dp[i][cnt][0]=max(prices[i]+dp[i+1][cnt+1][1],dp[i+1][cnt][0]);
                }
                else{
                    dp[i][cnt][1]=dp[i+1][cnt][1];
                    dp[i][cnt][0]=dp[i+1][cnt][0];
                }
            }
        }
        return dp[0][0][1];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
        return solve(prices,prices.size(),dp);
    }
};
