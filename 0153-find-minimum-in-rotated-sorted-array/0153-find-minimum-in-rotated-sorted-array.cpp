class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0,end=nums.size()-1,minEle = INT_MAX;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]<nums[end]){
            return nums[0];
        }
        while(start<=end) {
            int mid = (start+end)/2;
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            
            else if(nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            
            else if(nums[mid]>nums[0]){
                start = mid+1;
            }else {
                end = mid-1;
            }
        }
        return INT_MAX;
    }
};