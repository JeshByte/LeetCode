class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0,j=0;
        int ans=0;
        while(j<n){
            if(j+1<n && prices[j+1]>prices[i]){
                ans=max(ans,prices[j+1]-prices[i]);
            }
            else{
                i=j+1;
            }
            j++;
        }
        return ans;
    }
};
