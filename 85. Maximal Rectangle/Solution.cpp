class Solution {
public:
    vector<int> nextSmallest(vector<int>& heights, int n){
        stack<pair<int,int>>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int tp=n;
            while(!st.empty()){
                if(st.top().first<heights[i]){
                    tp=st.top().second;
                    break;
                }
                st.pop();
            }
            ans[i]=tp;
            st.push({heights[i],i});
        }
        return ans;
    }
    vector<int> prevSmallest(vector<int>& heights, int n){
        stack<pair<int,int>>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int tp=-1;
            while(!st.empty()){
                if(st.top().first<heights[i]){
                    tp=st.top().second;
                    break;
                }
                st.pop();
            }
            ans[i]=tp;
            st.push({heights[i],i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next=nextSmallest(heights,n);
        vector<int>prev=prevSmallest(heights,n);
        int ans=-1;
        for(int i=0;i<n;i++){
            int width=next[i]-prev[i]-1;
            ans=max(ans,width*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //cout<<n<<" "<<m<<'\n';
        vector<int> heights(m+1,0);
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    //cout<<"hi"<<'\n';
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            // for(int j=0;j<m;j++){
            //     cout<<heights[j]<<" ";
            // }
            // cout<<'\n';
            ans=max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};
