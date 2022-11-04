//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int A[],int mid,int M,int N){
        int allocatedStu = 1,pages = 0;
        for(int i=0;i<N;i++){
            if(A[i]>mid) return false;
            if(pages+A[i]>mid){
                allocatedStu+=1;
                pages=A[i];
            }else
                pages+=A[i];
        }
        return allocatedStu<=M;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M) return -1;
        int sum=0,maxN=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            maxN = max(maxN,A[i]);
        }
        int low = maxN,hi = sum,ans = -1;
        while(low<=hi) {
            int mid = (low+hi)/2;
            if(isPossible(A,mid,M,N)){
                ans = mid;
               
                hi = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends