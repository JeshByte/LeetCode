class Solution {
public:
    int solve(string& s, string& p, vector<vector<int>>& dp, int& n, int& m){
        int len=m;
        for(int i=m-1;i>=0;i--){
            if(p[i]=='*'){
                len=i;
            }
            else{
                break;
            }
        }
        for(int j=len;j<m;j++){
            dp[n][j]=1;
        }
        dp[n][m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                        int ans=0;
        if(p[j]=='?'){
            ans=dp[i+1][j+1];
        }
        else if(p[j]=='*'){
            ans=dp[i][j+1]+dp[i+1][j];
            if(ans>0){
                //cout<<i<<" "<<j<<'\n';
                ans=1;
            }
        }
        else{
            if(s[i]==p[j]){
                ans=dp[i+1][j+1];
            }
        }
        dp[i][j]=ans;
            }
        }

        return dp[0][0];
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=solve(s,p,dp,n,m);
        if(ans==1){
            return true;
        }
        return false;
    }
};
