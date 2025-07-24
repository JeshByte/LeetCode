class Solution {
public:
    int dfs2(int v,int parent,vector<vector<int>>& adj,int &res,int& total,vector<int>& nums,int ancestor,int ans1){
        int xorr=nums[v];
        for(auto it:adj[v]){
            if(it==parent){
                continue;
            }
            xorr^=dfs2(it,v,adj,res,total,nums,ancestor,ans1);
        }
        if(parent==ancestor){
            return xorr;
        }
        res=min(res,max({ans1,xorr,total^xorr^ans1})-min({ans1,xorr,total^xorr^ans1}));
        return xorr;
    }
    int dfs(int v,int parent,vector<vector<int>>& adj,int& res,int& total,vector<int>& nums){
        int xorr=nums[v];
        for(auto it:adj[v]){
            if(it==parent){
                continue;
            }
            xorr^=dfs(it,v,adj,res,total,nums);
        }
        if(parent!=-1){
            dfs2(parent,v,adj,res,total,nums,v,xorr);
        }
        return xorr;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res=INT_MAX;
        int total=0;
        for(int i=0;i<n;i++){
            total^=nums[i];
        }
        dfs(0,-1,adj,res,total,nums);
        return res;
    }
};
