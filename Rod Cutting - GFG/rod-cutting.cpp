//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int i,int price[], int n, vector<vector<int>> &dp) {
        if(i==0){
            return n * price[i];
        }
        if(dp[i][n]!=-1) return dp[i][n];
        int take = -1e9;
        if((i+1)<=n)
            take = price[i]+f(i,price,n-i-1,dp);
        int notTake = f(i-1,price,n,dp);
        return dp[i][n] = max(take,notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends