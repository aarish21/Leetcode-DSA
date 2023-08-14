class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
       
        sort(s.begin(),s.end());
        string f = s[0],l = s[s.size()-1];
        int ans=0;
        for(int i=0; i<s[0].size(); i++){
           if(f[i]!=l[i]){
               break;
           }
            cout<<ans;
            ans=i+1;
        }
        return s[0].substr(0, ans);
    }
};