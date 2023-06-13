class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0;i<g.size();i++){
            
            while(j<s.size()){
                if(s[j]>=g[i]){
                    count++;
                    j++;
                    cout<<j;
                    break;
                }else{j++;}
            }
            // if(j==s.size()) break;
        }
        return count;
    }
};