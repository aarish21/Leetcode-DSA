class Solution {
public:
   bool f(int ind,vector<int>& nums,int k, int target, int curSum,vector<bool> &visited){
       if(k==1)
           return true;
       if(ind>=nums.size()) return false;
       if(target==curSum)
           return f(0,nums,k-1,target,0,visited);
       
       for(int i=ind;i<nums.size();i++){
           if(visited[i] || curSum+nums[i]>target)
               continue;
           visited[i] = true;
           if (f(i+1,nums,k,target,curSum+nums[i],visited)) return true;
           visited[i] = false;
           
       }
       return false;
    }
  
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < k || sum % k) return false;
        vector<bool> visited(nums.size(),false);
        sum = sum/k;
        return f(0,nums,k,sum,0,visited);
        
        
    }
};