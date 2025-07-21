#include <vector>
#include <set>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
    using ll=long long;
public:
    std::vector<int> popcountDepth(std::vector<long long>& nums, std::vector<std::vector<long long>>& queries) {
        std::vector<int> depth(65);
        for (int i = 2; i <= 64; ++i)
            depth[i] = depth[__builtin_popcountll(i)] + 1;

        int n = nums.size();
        std::vector<int> curr_depth(n);
        std::vector<ordered_set<int>> comp(6);

        for (int i = 0; i < n; ++i) {
            int d = (nums[i] == 1) ? 0 : depth[__builtin_popcountll(nums[i])] + 1;
            curr_depth[i] = d;
            comp[d].insert(i);
        }

        std::vector<int> ans;

        for (const auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2], k = q[3];
                auto& s = comp[k];
                auto it1 = s.order_of_key(l);
                auto it2 = s.order_of_key(r+1);
                ans.push_back(it2-it1);
            } else {
                int idx = q[1];
                long long val = q[2];

                int old_d = curr_depth[idx];
                comp[old_d].erase(idx);

                int new_d = (val == 1) ? 0 : depth[__builtin_popcountll(val)] + 1;
                comp[new_d].insert(idx);
                curr_depth[idx] = new_d;
            }
        }

        return ans;
    }
};
