class Solution {
public:
    int maxDepth(string s) {
        int left=0,right=0;
        int ans=0;
        for(char x :s){
            if(x == '(')
                left++;
            else if(x==')')
                right++;
            
            ans = max(ans,left-right);
          
        }
        return ans;
    }
};