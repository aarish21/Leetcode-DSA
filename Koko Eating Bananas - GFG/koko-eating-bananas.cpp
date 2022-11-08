//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& piles, int h) {
        // Code here
        int start=1,  end = 1000000000;
        int res = end;
        
        while(start<=end){
            int mid = (start+end)/2;
            long long int hours = 0;
            for(int x: piles){
                hours += ceil(x*1.0/mid);
                
            }
            // cout<<hours<<" ";
            if(hours<=h){
                res = min(res,mid);
                end = mid-1;
            }else{
                start = mid+1;
            }
            
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends