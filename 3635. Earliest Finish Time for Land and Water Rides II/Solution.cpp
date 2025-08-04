#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMinTime(const vector<tuple<int, int, int>>& primaryTasks,
                   const vector<tuple<int, int, int>>& secondaryTasks) {
        int n = primaryTasks.size();
        int m = secondaryTasks.size();
        vector<tuple<int, int, int>> sortedSecondaryTasks = secondaryTasks;
        sort(sortedSecondaryTasks.begin(), sortedSecondaryTasks.end(),
             [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
                 return get<0>(a) < get<0>(b);
             });
        vector<int> minDurPrefix(m);
        minDurPrefix[0] = get<1>(sortedSecondaryTasks[0]);
        for (int i = 1; i < m; ++i) {
            minDurPrefix[i] =
                min(minDurPrefix[i - 1], get<1>(sortedSecondaryTasks[i]));
        }
        vector<int> minFinishSuffix(m);
        minFinishSuffix[m - 1] = get<2>(sortedSecondaryTasks[m - 1]);
        for (int i = m - 2; i >= 0; --i) {
            minFinishSuffix[i] =
                min(minFinishSuffix[i + 1], get<2>(sortedSecondaryTasks[i]));
        }
        int minOverallTime = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int primaryFinishTime = get<2>(primaryTasks[i]);
            auto it =
                upper_bound(sortedSecondaryTasks.begin(),
                            sortedSecondaryTasks.end(), primaryFinishTime,
                            [](int val, const tuple<int, int, int>& task) {
                                return val < get<0>(task);
                            });
            int idx = it - sortedSecondaryTasks.begin();

            int timeIfNoWait = INT_MAX;
            if (idx > 0) {
                timeIfNoWait = primaryFinishTime + minDurPrefix[idx - 1];
            }

            int timeIfWait = INT_MAX;
            if (idx < m) {
                timeIfWait = minFinishSuffix[idx];
            }

            minOverallTime = min(minOverallTime, min(timeIfNoWait, timeIfWait));
        }

        return minOverallTime;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<tuple<int, int, int>> landTasks(n);
        for (int i = 0; i < n; ++i) {
            landTasks[i] = {landStartTime[i], landDuration[i],
                            landStartTime[i] + landDuration[i]};
        }

        vector<tuple<int, int, int>> waterTasks(m);
        for (int i = 0; i < m; ++i) {
            waterTasks[i] = {waterStartTime[i], waterDuration[i],
                             waterStartTime[i] + waterDuration[i]};
        }

        int minTime_LW = getMinTime(landTasks, waterTasks);
        int minTime_WL = getMinTime(waterTasks, landTasks);

        return min(minTime_LW, minTime_WL);
    }
};
