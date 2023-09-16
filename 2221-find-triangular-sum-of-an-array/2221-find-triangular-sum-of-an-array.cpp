class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> prev;
        prev = nums;
        while(prev.size()!=1){
            vector<int> temp;
            for(int i=0;i<prev.size()-1;i++){
                int x = prev[i]+prev[i+1];
                temp.push_back(x%10);
            }
            prev = temp;
        }
        return prev[0];
        
    }
};