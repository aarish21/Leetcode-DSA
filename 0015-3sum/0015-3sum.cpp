class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end()); 
        map<int,int> map;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=i;
        }
        for(int x=0;x<nums.size();++x){
          
            if(nums[x] > 0){     
                break;
            }

            
            
            for(int i=x+1;i<nums.size();++i){
                int target = -(nums[x]+nums[i]);
                vector<int> temp;
                
                if(map.count(target)>=1 && map.find(target)->second > i){
                    temp.push_back(nums[x]);
                    temp.push_back(nums[i]);
                    temp.push_back(target);
                    ans.push_back(temp);
                }
                i = map.find(nums[i])->second;
            }
            x = map.find(nums[x])->second; 
           
        }
        return ans;
//         for(int i = 0 ; i < nums.size()  ; i++){    
//             if(nums[i] > 0){     
//                 break;
//             }
//             for(int j = i + 1 ; j < nums.size()  ; j++){ 
                
//                 int required = -(nums[i] + nums[j]);  
                
//                 if(hashMap.count(required) && hashMap.find(required)->second > j){ 
                    
//                     ans.push_back({nums[i] , nums[j] , required});
                    
//                 }
                
//                 j = hashMap.find(nums[j])->second; 
//             }
            
//             i = hashMap.find(nums[i])->second;    
//         }
        // return ans;  
        
    }
};