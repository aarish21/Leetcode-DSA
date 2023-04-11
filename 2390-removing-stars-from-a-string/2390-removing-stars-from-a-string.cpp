class Solution {
public:
    string removeStars(string s) {
        stack<char> a;
        int i=0;
        while(i<s.length()){
            if(s[i]=='*'){
                if(a.empty()){
                    i++;
                }else{
                    a.pop();
                    i++;
                }
            }else{
                a.push(s[i]);
                i++;
            }
        }
        string ans;
        while(!a.empty()) {
            ans.push_back(a.top());
            a.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};