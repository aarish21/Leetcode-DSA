class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxWater = 0;
        int i=0,j=height.size()-1;
        // for(int i=0;i<height.size();i++){
        //     for(int j=i+1;j<height.size();j++){
        //         int water = min(height[j],height[i])*(j-i);
        //         maxWater = max(maxWater,water);
        //     }
        // }
        while(i<j){
            
            int water = min(height[j],height[i])*(j-i);
            maxWater = max(maxWater,water);
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
            
        }
        return maxWater;
    }
};