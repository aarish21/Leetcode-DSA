class Solution {
public:
   
//     int helper(int i,vector<vector<int>> jobs,vector<int> &dp,int dep) {
//         if(i>=jobs.size()) return 0;
//         if(jobs[i][0]<dep) return helper(i+1,jobs,dp,dep);
//         if(dp[i]!=-1)return dp[i];
        
//         int notTake  = helper(i+1,jobs,dp,0);
//         int take = jobs[i][2] + helper(i+1,jobs,dp,jobs[i][1]);
//         return dp[i]=max(take,notTake);
//     }
//    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         int n = startTime.size();
//         vector<vector<int>> jobs;
//         vector<int> dp(startTime.size(),-1);
//         for (int i = 0; i < n; ++i) {
//             jobs.push_back({startTime[i], endTime[i], profit[i]});
//         }
//         sort(jobs.begin(), jobs.end());
//         dp[jobs.size()] = 0;
//         for(int i=n;i>=0;i--){
//             if(jobs[i][0]<dep) return helper(i+1,jobs,dp,dep);
//             if(dp[i]!=-1)return dp[i];

//             int notTake  = helper(i+1,jobs,dp,0);
//             int take = jobs[i][2] + dp[i+1] 
               
//             dp[i]=max(take,notTake);
//         }
//         return helper(0,jobs,dp,0);
//     }
    int memo[50001] = {};
    int dfs(vector<vector<int>>& comb, int pos, int last){
        if(pos >= comb.size()) return 0; // end of array
        if(comb[pos][0] < last) return dfs(comb, pos+1, last); // not allowed to take
        if(memo[pos] != -1) return memo[pos]; // return previously computed result
        int ans = 0;
        ans = max(dfs(comb, pos+1, comb[pos][1])+comb[pos][2], dfs(comb, pos+1, 0)); // either schedule job and take the profit and add a 'last' constraint, or skip the job and reset the last constraint
        return memo[pos] = ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(memo, -1, sizeof memo);
        vector<vector<int>> comb; // more convenient to put all values in one vector, also allows concurrent sorting
        for(int i = 0; i < startTime.size(); i++) comb.push_back({startTime[i], endTime[i], profit[i]});
        sort(comb.begin(), comb.end());
        return dfs(comb, 0, 0);
    }
};