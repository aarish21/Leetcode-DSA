#include<cmath>
class Solution {
public:
    int maxNoPiles(vector<int> piles) {
        int res = 0;
        for(int i:piles){
            res = max(res,i);
        }
        
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,  end = maxNoPiles(piles);
        int res = end;
        
        while(start<=end){
            int mid = (start+end)/2;
            long long int hours = 0;
            for(int x: piles){
                hours += ceil(x*1.0/mid);
                
            }
            // cout<<hours<<" ";
            if(hours<=h){
                res = min(res,mid);
                end = mid-1;
            }else{
                start = mid+1;
            }
            
        }
        return res;
        
    }
};