class Solution {
public:
    string frequencySort(string s) {
       vector<pair<int,char>> map('z'+1,{0,0});
        string res="";
        for(char a: s)
            map[a] = {map[a].first+1,a};
        
        sort(map.begin(),map.end());
        
        for(auto p: map)
            res = string(p.first,p.second) + res;
        
        return res;
    }
};