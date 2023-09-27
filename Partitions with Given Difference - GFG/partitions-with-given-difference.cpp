//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  const long M = 1000000007;
   
   int f(int i,vector<int>& arr, int k,vector<vector<int>> &dp){
        if(dp[i][k]!=-1) return dp[i][k];
        if(i==0){
            if(arr[0]==0 && k == 0) return 2;
            if(k==0 || k == arr[0]) return 1;
            return 0;
        }
        
        int take=0;
        if(arr[i]<=k)
            take = f(i-1,arr,k-arr[i],dp);
        int notTake = f(i-1,arr,k,dp);
       
        return dp[i][k] = (take+notTake)%M;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
       
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    if(sum-d<0) return 0;
        if((sum-d)%2==1) return 0;
	    int s2 = (sum-d)/2;
	   
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    return f(n-1,arr,s2,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends