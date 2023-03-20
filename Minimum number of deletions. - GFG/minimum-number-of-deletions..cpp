//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

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
int minDeletions(string str, int n) { 
    //complete the function here 
    int x = longestPalindromeSubseq(str);
    return n-x;
} 