class Solution {
public:
    int solve(string& word1, string& word2, vector<vector<int>>& dp){
        int n=word1.size();
        int m=word2.size();
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n && j==m){
                    continue;
                }
                        int ans=0;
        if(i<word1.size() && j<word2.size()){
            if(word1[i]==word2[j]){
                ans=0+dp[i+1][j+1];
            }
            else{
                ans=1+min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
            }
        }
        else if(i>=word1.size() && j<word2.size()){
            ans=1+dp[i][j+1];
        }
        else if(i<word1.size() && j>=word2.size()){
            ans=1+dp[i+1][j];
        }
        dp[i][j]=ans;
            }
        }

        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        return solve(word1,word2,dp);
    }
};
