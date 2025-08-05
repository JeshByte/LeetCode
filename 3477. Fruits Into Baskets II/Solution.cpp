class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int ans=0;
        set<int> used;
        for(int i=0;i<n;i++){
            bool poss=false;
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i] && !used.count(j)){
                    poss=true;
                    used.insert(j);
                    break;
                }
            }
            if(!poss){
                ans++;
            }
        }
        return ans;
    }
};
