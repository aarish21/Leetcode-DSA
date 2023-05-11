class Solution {
public:
    int helper(int i,int j, vector<int>& num1, vector<int>& num2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0,notTake=0;
        if(num1[i]==num2[j])
            take = 1+helper(i-1,j-1,num1,num2,dp);
        
        else
            notTake = max(helper(i-1,j,num1,num2,dp),helper(i,j-1,num1,num2,dp));
        
        return dp[i][j] = max(take,notTake);
    }
    int maxUncrossedLines(vector<int>& num1, vector<int>& num2) {
    
        int n=num1.size();
        int m=num2.size();

        vector<int> prev(m+1,0),cur(m+1,0);
       

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(num1[ind1-1]==num2[ind2-1])
                    cur[ind2] = 1 + prev[ind2-1];
                else
                    cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
            }
            prev = cur;
        }

        return prev[m];
    }
};