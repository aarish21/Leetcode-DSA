class Solution {
public:
//     string frequencySort(string s) {
//        vector<pair<int,char>> map('z'+1,{0,0});
//         string res="";
//         for(char a: s)
//             map[a] = {map[a].first+1,a};
        
//         sort(map.begin(),map.end());
        
//         for(auto p: map)
//             res = string(p.first,p.second) + res;
        
//         return res;
//     }
    string frequencySort(string s) {
        unordered_map<char,int> freq;           //for frequency of characters
        priority_queue<pair<int,char>> maxheap; 
        //maxheap according to frequency of characters
        for(char c: s)
            freq[c]++;
        for(auto it: freq)
            maxheap.push({it.second,it.first}); 
        //heap will be constructed on the basis of frequency
        s="";   
        while(!maxheap.empty()){
            s+=string(maxheap.top().first,maxheap.top().second); 
            //frequency times the character
            maxheap.pop();
        }
        return s;
    }
};