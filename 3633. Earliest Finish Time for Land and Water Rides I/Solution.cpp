class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int start=landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                int time=start;
                if(start<=waterStartTime[j]){
                    time+=(waterStartTime[j]-start);
                }
                time+=waterDuration[j];
                ans=min(ans,time);
            }
        }
        for(int i=0;i<m;i++){
            int start=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                int time=start;
                if(start<=landStartTime[j]){
                    time+=(landStartTime[j]-start);
                }
                time+=landDuration[j];
                ans=min(ans,time);
            }
        }
        return ans;
    }
};
