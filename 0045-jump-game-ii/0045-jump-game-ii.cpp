class Solution {
public:
    int jump(vector<int>& nums) {
        int r=0,l=0,farthest=0,ans=0;
        
        while(r<nums.size()-1){
            // farthest=0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            ans++;
        }
        return ans;
        
    }
};