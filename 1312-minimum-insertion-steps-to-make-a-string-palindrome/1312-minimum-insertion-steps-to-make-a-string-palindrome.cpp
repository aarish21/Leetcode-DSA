class Solution {
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
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
    int minInsertions(string s) {
        int n = s.length();
        int x = longestPalindromeSubseq(s);
        return n-x;
    }
};