//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &arr) {
        // code here
        // stack<int> s;
        // for( int i=0;i<arr.size();i++){
        //     if(s.empty()){
        //          s.push(arr[i]);
        //          continue;
        //     }else if(x>0){
        //         s.push(x);
        //     }else if(x<0 && s.top()>0){
        //         if(abs(x)>s.top()){
        //             s.pop();
        //             s.push(x);
        //         }else if(abs(x)==s.top()){
        //             s.pop();
        //         }
        //         else{
        //             continue;
        //         }
        //     }
        // }
        stack<int> st;
        st.push(arr[0]);
        
        for(int i=1;i<n;i++){
            if(st.empty()){
                st.push(arr[i]);
                // continue;
            }
            else if(arr[i]>0){
                st.push(arr[i]);
                // continue;
            }
            
            else if(arr[i]<0 && st.top()<0){
                st.push(arr[i]);
            }
            else if(st.top()>0 && arr[i]<0 && st.top()<abs(arr[i])){
                st.pop();
                i--;
            }
            else if((st.top()>0 && arr[i]<0)&&(st.top()==abs(arr[i])))
                st.pop();
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends