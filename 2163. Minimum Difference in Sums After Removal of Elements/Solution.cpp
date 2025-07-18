class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long n=(nums.size())/3;
        priority_queue<long long> maxi;
        vector<long long> right(3*n,-1);
        long long rsum=0;
        for(long long i=0;i<2*n;i++){
            maxi.push(nums[i]);
            rsum+=nums[i];
            if(maxi.size()>n){
                rsum-=maxi.top();
                maxi.pop();
            }
            if(maxi.size()==n){
                right[i]=rsum;
            }
        }
        priority_queue<long long,vector<long long>,greater<long long>> mini;
        vector<long long> left(3*n,-1);
        long long lsum=0;
        for(long long i=3*n-1;i>=n;i--){
            mini.push(nums[i]);
            lsum+=nums[i];
            if(mini.size()>n){
                lsum-=mini.top();
                mini.pop();
            }
            if(mini.size()==n){
                left[i]=lsum;
            }
        }
        long long ans=1e10;
        for(long long i=0;i<3*n;i++){
            if(right[i]==-1){
                continue;
            }
            ans=min(ans,right[i]-left[i+1]);
        }
        return ans;
    }
};
