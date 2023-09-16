class Solution {
public:
    bool f(string s,string t, int n,int m){
       if(n==0) return true;
        if(m==0) return false;
        if(s[n-1]==t[m-1])
           return f(s,t,n-1,m-1);
        return  f(s,t,n,m-1);
    }
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return true;
        if(t.size()==0) return false;
        return f(s,t,s.size(),t.size());
    }
};