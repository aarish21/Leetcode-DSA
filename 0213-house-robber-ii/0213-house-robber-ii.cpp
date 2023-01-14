class Solution {
public:
    int solve( vector<int>& arr,int start, int n){
        int prev = arr[start];
        int prev2 =0;
         //int n = arr.size();
        for(int i=start+1; i<n; i++){
            int pick = arr[i];
            if(i>1)
                pick += prev2;
            int nonPick = 0 + prev;

            int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev= cur_i;

        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n = nums.size();
        if(n==1) return nums[0];
        int robWithFirst = solve(nums, 0, nums.size() -1);
       int robWithLast = solve(nums, 1, nums.size());
       // for(int i = 0;i<nums.size();i++){
       //     if(i!=0) temp1.push_back(nums[i]);
       //     if(i!=n-1) temp2.push_back(nums[i]);
       // }
      
        return max(robWithFirst,robWithLast);
    }
};