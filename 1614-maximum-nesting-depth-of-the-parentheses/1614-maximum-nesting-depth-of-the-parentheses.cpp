class Solution {
public:
//     int maxDepth(string s) {
//         int left=0,right=0;
//         int ans=0;
//         for(char x :s){
//             if(x == '(')
//                 left++;
//             else if(x==')')
//                 right++;
            
//             ans = max(ans,left-right);
          
//         }
//         return ans;
//     }
    int maxDepth(string s) {
        int res = 0, cur = 0;
        for (char& c: s) {
            if (c == '(')
                res = max(res, ++cur);
            if (c == ')')
                cur--;
        }
        return res;
    }
};