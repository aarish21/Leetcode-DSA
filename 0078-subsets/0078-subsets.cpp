class Solution {
public:
    void solve(vector<int>& nums,int i,vector<int> &add,vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(add);
            return;
        }
        add.push_back(nums[i]);
        solve(nums,i+1,add,ans);
        add.pop_back();
        solve(nums,i+1,add,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> add;
        solve(nums,0,add,ans);
        return ans;
    }
};