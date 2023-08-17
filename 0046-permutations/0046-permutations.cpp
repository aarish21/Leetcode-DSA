class Solution {
    void solution(int index, vector<vector<int>> &ans, vector<int>& nums){
        if(index == nums.size()-1){
            ans.push_back(nums);
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solution(index+1,ans,nums);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solution(0,ans,nums);
        return ans;
    }
};