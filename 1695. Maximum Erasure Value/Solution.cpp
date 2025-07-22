class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        map<int,int> mp;
        int maxi=-1;
        int s=0;
        while(j<n){
            mp[nums[j]]++;
            s+=nums[j];
            if(mp[nums[j]]>1){
                while(i<n && mp[nums[j]]>1){
                    mp[nums[i]]--;
                    s-=nums[i];
                    i++;
                }
            }
            maxi=max(maxi,s);
            j++;
        }
        return maxi;
    }
};
