class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> scores;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            scores.push_back({nums2[i],nums1[i]});
        }
        sort(scores.rbegin(), scores.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum=0,res=0;
        for(int i=0;i<n;i++){
            pq.push(scores[i].second);
            sum+=scores[i].second;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                res=max(res,sum*scores[i].first);
            }
        }
        
        return res;
    }
};