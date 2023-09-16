class Solution {
    
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Initialize a 2D DP array dp, where dp[i][j] represents whether s[0:i-1] is a subsequence of t[0:j-1].
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // An empty string s is always a subsequence of t.
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = true;
        }
        
        // Fill in the DP table.
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // If the current characters match, move both pointers.
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // If they don't match, continue checking if s[0:i-1] is a subsequence of t[0:j-2].
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        
        // The result is in dp[m][n], which represents whether s[0:m-1] is a subsequence of t[0:n-1].
        return dp[m][n];
    }
};