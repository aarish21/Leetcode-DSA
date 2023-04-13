class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            while(!st.empty() && j<pushed.size() && st.top()==popped[j]){
                st.pop();
                j++;
            }
            
        }
        while(!st.empty()) {cout<<st.top(); st.pop();}
        return j==pushed.size();
    }
};