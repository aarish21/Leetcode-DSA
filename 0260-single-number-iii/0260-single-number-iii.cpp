class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo=0;
        
        for(int i=0;i<nums.size();i++){
            xo^=nums[i];
        }
        int count=0;
        while(xo!=0){
            if(xo&1) break;
            count++;
            xo = xo>>1;
        }
        int xor1=0,xor2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<count)){
                xor1 = xor1^nums[i];
            }else{
                xor2 = xor2^nums[i];
            }
        }
        return {xor1,xor2};
    }
};