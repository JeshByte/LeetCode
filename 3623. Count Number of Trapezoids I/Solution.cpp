class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long MOD=1e9+7;
        map<long long,long long>mp;
        long long n=points.size();
        for(long long i=0;i<n;i++){
            mp[points[i][1]]++;
        }
        vector<long long> comp;
        for(auto it:mp){
            long long req=(((it.second)*(it.second-1)))/2;
            comp.push_back(req);
        }
        long long s=0;
        for(long long i=0;i<comp.size();i++){
            s+=comp[i];
        }
        long long ans=0;
        for(long long i=0;i<comp.size();i++){
            s-=comp[i];
            ans=(ans+((comp[i]*s)%MOD))%MOD;
        }
        return ans;
    }
};
