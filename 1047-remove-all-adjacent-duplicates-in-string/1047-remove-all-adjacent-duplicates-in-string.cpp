class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(auto a: s){
            if(ans.size() && ans.back() == a)
                ans.pop_back();
            else
                ans.push_back(a);
        }
       return ans;
    }
};