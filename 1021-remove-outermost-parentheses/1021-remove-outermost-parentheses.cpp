class Solution {
public:
    string removeOuterParentheses(string s) {
//         stack<char> stc;
//         string output;
        
//         for(int i=0;i<s.length();i++){
//             char ch = s.at(i);
//             if(ch == '('){
//                 if(stc.size()>0){
//                     output+=ch;
//                 }
//                 stc.push(ch);
//             }else{
//                 stc.pop();
//                 if(stc.size()>0){
//                     output+=ch;
//                 }
//             }
//         }
//         return output;
         string res;
        int opened = 0;
        for (char c : s) {
            if(c == '(') {
                if(opened > 0) res += c;;
                opened++;
            } else {
                if(opened > 1) res += c;
                opened--;
            }
        }
        return res;
    }
};