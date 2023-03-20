//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<int> curr(m + 1, 0), prev(m + 1, 0);

       	// no need to write base case as we already declare our dp as 0

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }
        return curr[m];
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = longestCommonSubsequence(str1,str2);
	    int s1 = str1.length();
	    int s2 = str2.length();
	    return s1+s2-2*n;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends