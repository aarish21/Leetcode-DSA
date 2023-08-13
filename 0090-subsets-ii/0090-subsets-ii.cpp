class Solution {
     void solve(vector<int>& nums,int i,vector<int> &add,set<vector<int>> &ans){
        if(i==nums.size()){
            ans.insert(add);
            return;
        }
        add.push_back(nums[i]);
        solve(nums,i+1,add,ans);
        add.pop_back();
        solve(nums,i+1,add,ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> add;
        solve(nums,0,add,ans);
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
};