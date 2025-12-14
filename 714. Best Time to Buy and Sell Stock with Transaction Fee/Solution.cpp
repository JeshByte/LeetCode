class Solution {
public:
    int solve(vector<int>& prices,int n,vector<vector<int>>& dp,int fee){
        dp[n-1][0]=prices[n-1]-fee;
        dp[n-1][1]=0;
        for(int i=n-2;i>=0;i--){
            int op1=prices[i]-fee+dp[i+1][1];
            int op2=dp[i+1][0];
            dp[i][0]=max(op1,op2);
            op1=dp[i+1][0]-prices[i];
            op2=dp[i+1][1];
            dp[i][1]=max(op1,op2);
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        return solve(prices,n,dp,fee);
    }
};
