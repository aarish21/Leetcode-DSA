class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==k) return nums;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        priority_queue<int> pq;
        for(auto i:map){
            pq.push(i.second);
        }
        
        vector<int> ans;
        int j=0;
        while(j<k){
            for(auto i:map){
                if(i.second==pq.top()){
                    ans.push_back(i.first);
                    map.erase(i.first);
                    pq.pop();
                    break;
                } 
            }
            j++;
        }
        return ans;
       
    }
};