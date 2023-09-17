class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        int prev1=0,prev2=0;
        for(int ind=n;ind>=0;ind--){
            int cur = cost[ind]+ min(prev1,prev2);
            prev2 = prev1;
            prev1= cur;
        }
        return min(prev1,prev2);
    }
};