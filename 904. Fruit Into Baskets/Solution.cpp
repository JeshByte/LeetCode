class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        map<int,int> mp;
        set<int> st;
        int i=0,j=0;
        int ans=-1;
        while(j<n){
            mp[fruits[j]]++;
            st.insert(fruits[j]);
            if(st.size()>2){
                while(i<n && st.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]<=0){
                        st.erase(fruits[i]);
                    }
                    i++;
                }
            }
            if(st.size()<=2){
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};
