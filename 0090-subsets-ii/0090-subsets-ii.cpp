class Solution {
     void solve(vector<int>& nums,int ind,vector<int> &add,vector<vector<int>> &ans){
        ans.push_back(add);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            add.push_back(nums[i]);
            solve(nums,i+1,add,ans);
            add.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> add;
        solve(nums,0,add,ans);
        return ans;
    }
};