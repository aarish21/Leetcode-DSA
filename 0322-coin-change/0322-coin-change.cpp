class Solution {
public:
    int helper(int ind,int amount, vector<int> &coin,vector<vector<int>> &dp){
    
        if(ind == 0){
            if(amount%coin[0]==0) return amount/coin[0];
            
            else return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake = helper(ind-1,amount,coin,dp);
        int take = 1e9;
        if(coin[ind]<=amount) 
            take = 1 + helper(ind,amount-coin[ind],coin,dp);
        return dp[ind][amount] = min(take,notTake);
        
        
    }
    int coinChange(vector<int>& arr, int amount) {
        int n = arr.size();
        vector<int> prev(amount+1,0),cur(amount+1,0);
       for(int i=0; i<=amount; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=amount; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];
                
             cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    
    int ans = prev[amount];
    if(ans >=1e9) return -1;
    return ans;
    }
};