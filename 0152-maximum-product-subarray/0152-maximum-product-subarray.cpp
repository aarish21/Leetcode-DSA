class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int ans= INT_MIN;
        int pre = 1 , post = 1;
        for(int i=0;i<nums.size();i++){
            if(pre==0) pre=1;
            if(post==0) post=1;
            pre = pre*nums[i];
            post = post*nums[nums.size()-i-1];
            ans = max(ans,max(pre,post));
        }
        return ans;
    }
};