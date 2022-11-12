class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,int> m1;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
            // m2[t[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(!m1.count(t[i]) || m1[t[i]] <= 0)
                return false;
            else
                m1[t[i]]--;
        }
        return true;
        
    }
};