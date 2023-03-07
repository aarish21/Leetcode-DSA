class Solution {
public:
    bool subSetSum(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i==0) return nums[0]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        bool notTake = subSetSum(i-1,target,nums,dp);
        bool take = false;
        if(nums[i]<=target) take = subSetSum(i-1,target-nums[i],nums,dp);
        
        return dp[i][target] = take || notTake;
        
        
    }
    bool canPartition(vector<int>& nums) {
       
        int totalSum = 0;
        for(int x: nums) totalSum+=x;
        int target = totalSum/2;
        if(totalSum%2 == 1) return false;
         vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return subSetSum(nums.size()-1,target,nums,dp);
    }
};