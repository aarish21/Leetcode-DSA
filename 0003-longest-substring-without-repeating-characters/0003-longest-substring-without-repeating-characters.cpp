class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int maxi=0;
        int left =0;
       
        for(int i=0;i<s.length();i++){
           if(!st.count(s[i])){
               st.insert(s[i]);
               maxi=max(maxi,i-left+1);
           }else{
            
               while(s[left]!=s[i]){
                    st.erase(s[left]);
                    left++;
                }
                 left++;
                
           }
        }
        return maxi;
    }
};