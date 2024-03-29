class Solution {
public:
    int f(int i, vector<int>& nums, int target, vector<vector<int>> &dp) {
        if(i==-1 &&  target==0) return 1;
        if(i==-1) return 0;
        if(dp[i][target+2000]!=-1) return dp[i][target+2000];
        int take1 = f(i-1,nums,+nums[i]+target,dp);
        int take2 = f(i-1,nums,-nums[i]+target,dp);
        return dp[i][target+2000] = take1+take2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(5005,-1));
        return f(nums.size()-1,nums,target, dp);
    }
    
   
};