class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size() == 1){
            return strs[0];
        }
         int idx = INT_MAX;
        int len = strs[0].length();
        for(int i=0;i<strs.size()-1;i++){
            int y = strs[i+1].length();
            len = min(y,len);
            cout<<len<< " ";
            if(len == 1){
               if(strs[i][0]==strs[i+1][0]){
                   idx = 1;
               } else {
                   idx = 0;
                   break;
               }
            }
          for(int j=0;j<len;j++){
              if(strs[0][j] != strs[i+1][j]){
                  idx = min(j,idx);
                  
              } else {
                  // idx = len-1;
                  
              }
          }
        }
        cout<<idx;
        if(idx == INT_MAX){
            idx = len;
        }
        return strs[0].substr(0,idx);
    }
};