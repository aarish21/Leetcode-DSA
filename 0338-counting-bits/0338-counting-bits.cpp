class Solution {
public:
    int numOfBits(int n){
        int count=0;
        while(n!=0){
          n = n&(n-1);
          count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int x = numOfBits(i);
            ans.push_back(x);
        }
        return ans;
    }
};