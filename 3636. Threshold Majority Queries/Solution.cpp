#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    struct Q {
        int l, r, t, idx;
    };
    std::vector<int> subarrayMajority(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        std::vector<Q> comp;
        for(int i = 0; i < q; i++) {
            comp.push_back({queries[i][0], queries[i][1], queries[i][2], i});
        }
        
        int Root = std::max(1, (int)sqrt(n));
        std::sort(comp.begin(), comp.end(), [&](auto val1, auto val2) {
            int b1 = val1.l / Root;
            int b2 = val2.l / Root;
            if(b1 != b2) {
                return b1 < b2;
            }
            return val1.r > val2.r;
        });

        std::unordered_map<int, int> freq;
        int bestF = 0;
        std::vector<int> ans(q, -1);
        std::vector<set<int>> bucket(n + 1);
        
        auto add = [&](int val) {
            int oldFreq = freq[val];
            if (oldFreq) {
                bucket[oldFreq].erase(val);
            }
            freq[val]++;
            bucket[oldFreq+1].insert(val);
            bestF = std::max(bestF, freq[val]);
        };
        
        auto remove = [&](int val) {
            int oldFreq = freq[val];
            freq[val]--;
            bucket[oldFreq].erase(val);
            if (freq[val]) { // Corrected check
                bucket[freq[val]].insert(val);
            }
            while(bestF > 0 && bucket[bestF].empty()) {
                bestF--;
            }
        };
        
        int L = 0, R = -1;
        for(int i = 0; i < q; i++){
            Q qv = comp[i];
            
            while(L > qv.l) { L--; add(nums[L]); }
            while(R < qv.r) { R++; add(nums[R]); }
            
            while(L < qv.l) { remove(nums[L]); L++; }
            while(R > qv.r) { remove(nums[R]); R--; }
            
            if(bestF >= qv.t){
                ans[qv.idx] = *bucket[bestF].begin();
            }
            else{
                ans[qv.idx] = -1;
            }
        }
        return ans;
    }
};
