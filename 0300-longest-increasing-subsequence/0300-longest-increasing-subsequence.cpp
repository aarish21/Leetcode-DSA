class Solution {
public:
    int helper(int ind,int prev,int n,vector<int> &nums,vector<vector<int>> &dp){
        if(ind == n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int notTake = 0+helper(ind+1,prev,n,nums,dp);
        int take = 0;

        if(prev==-1 || nums[ind]>nums[prev])
            take=1+helper(ind+1,ind,n,nums,dp);
        return dp[ind][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(0,-1,nums.size(),nums,dp);
    }
};