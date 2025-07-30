class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int i=0;
        vector<pair<int,int>> segs;
        while(i<n){
            if(nums[i]==maxi){
                int j=i;
                for(;j<n && nums[j]==maxi;j++);
                segs.push_back(make_pair(i,j-1));
                i=j;
            }
            else{
                i++;
            }
        }
        int ans=-1;
        for(int i=0;i<segs.size();i++){
            int len=segs[i].second-segs[i].first+1;
            ans=max(ans,len);
        }
        return ans;
    }
};
