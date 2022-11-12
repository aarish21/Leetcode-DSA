class Solution {
public:
    void rotate(string &s){
        char a = s[0];
        for(int i=1;i<s.length();i++)
            s[i-1]=s[i];
        s[s.length()-1] = a;
    }
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        for(int i=0;i<s.length();i++){
            if(s==goal)
                return true;
            rotate(s);
        }
        return false;
    }
};