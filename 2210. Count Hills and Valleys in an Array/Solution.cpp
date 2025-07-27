class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> comp;
        int n=nums.size();
        int i=0;
        while(i<n){
            comp.push_back(nums[i]);
            int start=i;
            while(i<n && nums[i]==nums[start]){
                i++;
            }
        }
        int ans=0;
        int len=comp.size();
        for(int i=1;i<=len-2;i++){
            if(comp[i]>comp[i-1] && comp[i]>comp[i+1]){
                ans++;
            }
            else if(comp[i]<comp[i-1] && comp[i]<comp[i+1]){
                ans++;
            }
        }
        return ans;
    }
};
