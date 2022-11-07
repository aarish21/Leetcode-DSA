class Solution {
public:
    bool isPossible(vector<int> A,int mid,int M,int N){
        int allocatedStu = 1,pages = 0;
        for(int i=0;i<N;i++){
            if(A[i]>mid) return false;
            if(pages+A[i]>mid){
                allocatedStu+=1;
                pages=A[i];
            }else
                pages+=A[i];
        }
        return allocatedStu<=M;
    }
    int splitArray(vector<int>& nums, int k) {
        int N = nums.size();
        if(N<k) return -1;
        int sum=0,maxN=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
            maxN = max(maxN,nums[i]);
        }
        int low = maxN,hi = sum,ans = -1;
        while(low<=hi) {
            int mid = (low+hi)/2;
            if(isPossible(nums,mid,k,N)){
                ans = mid;
               
                hi = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};