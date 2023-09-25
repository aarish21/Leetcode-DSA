//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    bool f(int i, int arr[],int k, vector<vector<int>> &dp){
        if(dp[i][k]!=false) return true;
        if(k==0) return true;
        if(i==0) return k==arr[0];
        int take = false;
        if(arr[i]<=k)
            take = f(i-1,arr,k-arr[i],dp);
        int notTake = f(i-1,arr,k,dp);
        return dp[i][k] = take||notTake;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    if(n==1) return arr[0];
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    
	    vector<vector<int>> dp(n,vector<int>(sum+1,false));
	    
	    for(int i=0;i<n;i++) dp[i][0]=true;
	    if(arr[0]<=sum) dp[0][arr[0]]=true;
	    
	    for(int i=1;i<n;i++){
	       for(int k=1;k<=sum;k++){
            int take = false;
            if(arr[i]<=k)
                take = dp[i-1][k-arr[i]];
            int notTake = dp[i-1][k];
            dp[i][k] = take||notTake;
	       }
	    }
	    int mini= 1e9;
	    for(int i=0;i<=sum;i++){
	        if(dp[n-1][i]==true){
	            int diff = abs(i-(sum-i));
	            mini = min(mini,diff);
	        }
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends