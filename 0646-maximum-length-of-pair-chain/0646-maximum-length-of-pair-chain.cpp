class Solution {
public:
    int f(int i,vector<vector<int>>& pairs,int &prev,vector<vector<int>> &dp){
        if(i==pairs.size()){
            return 0;
        }
        
        if(dp[i][prev+1001]!=-1) return dp[i][prev+1001];
        int take = -1e9;
        if(pairs[i][0]<pairs[i][1] && prev<pairs[i][0])
            take = 1+f(i+1,pairs,pairs[i][1],dp);
        int notTake = f(i+1,pairs,prev,dp);
        return dp[i][prev+1001] = max(take,notTake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(pairs.size()+1,vector<int>(2004,-1));
        int prev = -1001;
        return f(0,pairs,prev,dp);
    }
};