//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        reverse(s.begin(), s.end());
            int l = 0, r = 0, i = 0, n = s.size();
            while (i < n)
            {
                while (i < n && s[i] != '.')
                {
                    s[r++] = s[i++];
                }
                if (l < r)
                {
                    reverse(s.begin() + l, s.begin() + r);	// reverse current word
                    if (r == n) break;
                    s[r++] = '.';	// set empty space
                    l = r;
                }
                ++i;	// now i == n or s[i] == ' ', so we skip that character!
            }
            return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends