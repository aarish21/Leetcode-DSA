class Solution {
    
    bool helper(int i,int j,int cursum,vector<vector<int>> &dp,vector<int>& nums,int m){
        if(i==j) return true;
        if(cursum<m) return false;
        
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = helper(i+1,j,cursum-nums[i],dp,nums,m) || helper(i,j-1,cursum-nums[j],dp,nums,m);
        
       return dp[i][j]= ans;
    }
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n=nums.size(),sum=0;
        if(n<3) return true;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int x: nums){
            sum+=x;
        }
        return helper(0,n-1,sum,dp,nums,m);
    }
};