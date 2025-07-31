class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        set<int> res;
        set<int> prev;
        for(int i=0;i<n;i++){
            set<int> curr;
            curr.insert(arr[i]);
            for(auto it:prev){
                curr.insert(it|arr[i]);
            }
            for(auto it:curr){
                res.insert(it);
            }
            prev=curr;
        }
        return res.size();
    }
};
