//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

int f(int i,int j,vector<vector<int>> &dp){
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int down = 0,right=0;
    if(i>0)
        down = f(i-1,j,dp);
    if(j>0)
        right = f(i,j-1,dp);
    return dp[i][j] = down+right;
}
long long  numberOfPaths(int m, int n)
{
    // Code Here
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return f(m-1,n-1,dp);
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends