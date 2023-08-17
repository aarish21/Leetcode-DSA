class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mini=1e9,maxi=-1;
        int low = 0, high = nums.size()-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                maxi = max(mid,maxi);
                low = mid+1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        low = 0; high = nums.size()-1;
         while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                mini = min(mid,mini);
                high = mid-1;
            }
            
            else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(mini == 1e9) mini = -1 ; 
        return {mini,maxi};
    }
};