class Solution {
public:
    // memoization
    bool subSetSum(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i==0) return nums[0]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        bool notTake = subSetSum(i-1,target,nums,dp);
        bool take = false;
        if(nums[i]<=target) take = subSetSum(i-1,target-nums[i],nums,dp);
        
        return dp[i][target] = take || notTake;
    }
    // tabulation
    bool subsetSumToK1(int n, int k, vector<int> &arr){
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));

        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }

        if(arr[0]<=k)
            dp[0][arr[0]] = true;

        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=k; target++){

                bool notTaken = dp[ind-1][target];

                bool taken = false;
                    if(arr[ind]<=target)
                        taken = dp[ind-1][target-arr[ind]];

                dp[ind][target]= notTaken||taken;
            }
        }

        return dp[n-1][k];
    }
    // space optimization
    bool subsetSumToK(int n, int k, vector<int> &arr){
        vector<bool> prev(k+1,false);

        prev[0] = true;

        if(arr[0]<=k)
            prev[arr[0]] = true;

        for(int ind = 1; ind<n; ind++){
            vector<bool> cur(k+1,false);
            cur[0] = true;
            for(int target= 1; target<=k; target++){
                bool notTaken = prev[target];

                bool taken = false;
                    if(arr[ind]<=target)
                        taken = prev[target-arr[ind]];

                cur[target]= notTaken||taken;
            }
            prev = cur;
        }

        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
       
        int totalSum = 0;
        for(int x: nums) totalSum+=x;
        int target = totalSum/2;
        if(totalSum%2 == 1 || nums.size()<=1) return false;
         // vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return subsetSumToK(nums.size()-1,target,nums);
    }
};