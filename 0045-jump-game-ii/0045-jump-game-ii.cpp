class Solution {
public:
    int helper(int ind,vector<int>& nums,vector<int> &dp){
        if(ind >= nums.size()-1) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        int jumps=1e9;
        for(int i=1;i<=nums[ind];i++){
            int j = 1+helper(i+ind,nums,dp);
            jumps = min(jumps,j);
        }
        return dp[ind]=jumps;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        
        return helper(0,nums,dp);
    }
};