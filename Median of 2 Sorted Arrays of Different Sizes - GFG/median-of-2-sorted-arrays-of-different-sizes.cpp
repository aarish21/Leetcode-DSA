//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Your code goes here
    int n = nums1.size(), m = nums2.size();
            int k = (n+m+1)/2;
            if (m > n)
            {
                return MedianOfArrays(nums2, nums1);
            }
            int start = max(0, k - m), end = min(k, n);
            while (start <= end)
            {
                int mid1 = (start + end) / 2;
                int mid2 = k - mid1;
                int l1, l2, r1, r2;
                if (mid1 == 0)
                    l1 = INT_MIN;
                else
                    l1 = nums1[mid1 - 1];

                if (mid2 == 0)
                    l2 = INT_MIN;
                else
                    l2 = nums2[mid2 - 1];
                if (mid1 == n)
                    r1 = INT_MAX;
                else
                    r1 = nums1[mid1];

                if (mid2 == m)
                    r2 = INT_MAX;
                else
                    r2 = nums2[mid2];

                if (l1 <= r2 && l2 <= r1)
                    if( (n+m) % 2 == 0)
                        return (max(l1, l2)+ min(r1,r2))/2.0;
                    else 
                        return max(l1, l2);
                else if (l1 > r2)
                    end = mid1 - 1;
                else
                    start = mid1 + 1;
            }
            return 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends