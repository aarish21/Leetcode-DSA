class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int ans = -1,start = 1,end=nums.size()-2;
        if(nums.size() == 1) return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2])
            return nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
               return mid;
            }
            else if(nums[mid] < nums[mid-1]) end = mid - 1;
            else if(nums[mid] < nums[mid+1]) start = mid + 1;
            
        }
        return -1;
    }
};