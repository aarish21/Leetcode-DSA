#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        for(auto m: tokens){
            if(m=="+" || m=="-"|| m=="/"|| m=="*")
            {
                long x = s.top();
                s.pop();
                long y = s.top();
                s.pop();
                if(m == "+")
                    s.push(y+x);
                else if(m == "-")
                    s.push(y-x);
                else if(m == "*")
                    s.push(y*x);
                else
                    s.push(y/x);
            }
            else{
                int x = stoi(m);
                s.push(x) ;
            }
                
        }
         return s.top();
    }
        // int z = stoi(s.top());
         // cout<<s.size();
};