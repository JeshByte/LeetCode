class Solution {
    #define Ceil(a,b) ((a+b-1)/b)
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=sqrt(n);
        int blocks=Ceil(n,m);
        vector<int> maxi(blocks);
        for(int i=0;i<n;i++){
            maxi[i/m]=max(maxi[i/m],baskets[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            bool taken=false;
            for(int j=0;j<blocks;j++){
                if(maxi[j]<fruits[i]){
                    continue;
                }
                maxi[j]=-1;
                for(int k=0;k<m;k++){
                    int pos=j*m+k;
                    if(pos<n && baskets[pos]>=fruits[i] && !taken){
                        taken=true;
                        baskets[pos]=-1;
                    }
                    if(pos<n){
                        maxi[j]=max(maxi[j],baskets[pos]);
                    }
                }
                if(taken){
                   break; 
                }
            }
            if(!taken){
                ans++;
            }
        }
        return ans;
    }
};
