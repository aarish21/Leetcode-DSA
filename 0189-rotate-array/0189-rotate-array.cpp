class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=n-1;
        int rotate = n-(k%n);
        while(i<j){
            swap(nums[i++],nums[j--]);
        }
        
        int d = n-rotate-1;
        i=0;
        while(i<d){
            swap(nums[i++],nums[d--]);
        }
        
        i=n-rotate;
        d = n-1;
        while(i<d){
            swap(nums[i++],nums[d--]);
        }
    }
};