#include<cmath>
class Solution {
public:
    int maxNo(vector<int> piles) {
        int res = 0;
        for(int i:piles){
            res = max(res,i);
        }
        
        return res;
    }
    //  1 2 3 4 5
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1,end = 1e6,res=INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            int sum = 0;
            // cout<<mid<<" ";
            for(int x:nums){
                sum += ceil(x*1.0/mid);
            }
            cout<<sum<< " ";
            if(sum<=threshold){
                res = min(res,mid);
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return res;
    }
};