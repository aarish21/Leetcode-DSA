class Solution {
public:
    int helper(int ind, int target,vector<int>& nums,vector<vector<int>> &dp){
        
        if(ind == 0){
            if(target==0 && nums[0] == 0) return 2;
            if(target==0 || target==nums[0]) return 1;
            return 0;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int notTake = helper(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind]<=target) take = helper(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target] = (take + notTake);
    }
    int findTargetSumWays(vector<int>& nums, int d) {
        int n = nums.size();
        int totalSum = 0;
        for(int x: nums) totalSum += x;

        if(totalSum-d<0) return 0;
        if((totalSum-d)%2==1) return 0;
        int s2 = (totalSum-d)/2;
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return helper(n-1,s2,nums,dp);
    }
};