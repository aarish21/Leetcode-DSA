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
        int low=0,high=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                reverse(s.begin()+low,s.begin()+high+1);
                low = high = i+1;
            }else{
                high = i;
            }
        }
        reverse(s.begin()+low,s.begin()+high+1);
        reverse(s.begin(),s.end());
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