class Solution {
public:
    int memo[50001] = {};
    int helper(int i,vector<vector<int>> &jobs,int dep) {
        if(i>=jobs.size()) return 0;
        if(jobs[i][0]<dep) return helper(i+1,jobs,dep);
        if(memo[i]!=-1)return memo[i];
        
        int ans = 0;
        ans = max(helper(i+1,jobs, jobs[i][1])+jobs[i][2], helper(i+1,jobs, 0));
        return memo[i]=ans;
    }
   int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        memset(memo, -1, sizeof memo);
        vector<vector<int>> jobs;
        vector<int> dp(startTime.size(),-1);
        for (int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        return helper(0,jobs,0);
    }
  
};