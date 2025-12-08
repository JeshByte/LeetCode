class Solution {
public:
    // int solve(vector<int>& arr,map<pair<int,int>,int> maxi,int left,int right,vector<vector<int>>& dp){
    //     if(left==right){
    //         return 0;
    //     }
    //     if(dp[left][right]!=-1){
    //         return dp[left][right];
    //     }
    //     int ans=INT_MAX;
    //     for(int k=left;k<right;k++){
    //         ans=min(ans,maxi[{left,k}]*maxi[{k+1,right}]+solve(arr,maxi,left,k,dp)+solve(arr,maxi,k+1,right,dp));
    //     }
    //     dp[left][right]=ans;
    //     return dp[left][right];
    // }
    int solveTab(vector<int>& arr,map<pair<int,int>,int> maxi,vector<vector<int>>& dp){
        int n=arr.size();
        for(int i=0;i<=n;i++){
            dp[i][i]=0;
        }
        for(int left=n-1;left>=0;left--){
            for(int right=left+1;right<n;right++){
                int ans=INT_MAX;
        for(int k=left;k<right;k++){
            ans=min(ans,maxi[{left,k}]*maxi[{k+1,right}]+dp[left][k]+dp[k+1][right]);
        }
        dp[left][right]=ans;
            }
        }

        
        return dp[0][n-1];
    } 
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<n;j++){
                maxi[{i,j}]=max(maxi[{i,j-1}],arr[j]);
            }
        }
        return solveTab(arr,maxi,dp);
    }
};
