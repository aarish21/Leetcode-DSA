//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int start[], int dep[], int n)
    {
    	// Your code here
    	sort(start,start+n);
    	sort(dep,dep+n);
    	int i=1,j=0;
    	int platform=1,res=1;
    	while(i<n){
    	    if(start[i]<=dep[j]){
    	        platform++;
    	        i++;
    	    }else{
    	        platform--;
    	        j++;
    	    }
    	    res = max(platform,res);
    	}
    	return res;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends