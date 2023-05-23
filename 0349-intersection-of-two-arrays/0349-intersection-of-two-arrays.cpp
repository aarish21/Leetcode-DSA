class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int> ans;
        map<int,int> m,p;
        for(int i =0;i<nums1.size();i++){
            m[nums1[i]]=true ;
        }
      
      
     for(int i =0;i<nums2.size();i++){
            if(m[nums2[i]]==true){
                 ans.push_back(nums2[i]);
                m[nums2[i]]=false;
            }
     }
        
        return ans;
    }
};