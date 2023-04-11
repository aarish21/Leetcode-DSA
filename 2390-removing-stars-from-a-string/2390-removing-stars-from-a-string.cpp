class Solution {
public:
    string removeStars(string s) {
        string a;
        int i=0;
        while(i<s.length()){
            if(s[i]=='*'){
                a.pop_back();
                i++;
            }else{
                a.push_back(s[i]);
                i++;
            }
        }
        
        return a;
    }
};