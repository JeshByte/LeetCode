class Solution {
public:
int solve(vector<int>& prices,int n,vector<vector<vector<int>>>& dp,int k){
        for(int i=0;i<k;i++){
            dp[n-1][i][0]=prices[n-1];
            dp[n-1][i][1]=0;
        }
        dp[n-1][k][0]=dp[n-1][k][1]=0;
        for(int i=n-2;i>=0;i--){
            for(int cnt=k;cnt>=0;cnt--){
                if(cnt<k){
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
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        return solve(prices,prices.size(),dp,k);
    }
};
