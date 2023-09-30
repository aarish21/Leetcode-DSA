//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
  
    int f(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
    if (i == 0 || j == 0) return 0;

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = 0;
    if (s1[i - 1] == s2[j - 1]) {
        ans = 1 + f(i - 1, j - 1, s1, s2, dp);
    }

    dp[i][j] = ans;
    return ans;
}

int longestCommonSubstr(string S1, string S2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the answer to store the length of the longest common substring.
    int ans = 0;

    // Call the recursive function for all possible pairs of substrings.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                int val = f(i, j, S1, S2, dp);
                ans = max(ans, val);
            }
        }
    }

    return ans;
}

};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends