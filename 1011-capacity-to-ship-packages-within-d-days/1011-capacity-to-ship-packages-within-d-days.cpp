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
    int shipWithinDays(vector<int>& weights, int days) {
        int N = weights.size();
        if(N<days) return -1;
        int sum=0,maxN=0;
        for(int i=0;i<N;i++){
            sum+=weights[i];
            maxN = max(maxN,weights[i]);
        }
        int low = maxN,hi = sum,ans = -1;
        while(low<=hi) {
            int mid = (low+hi)/2;
            if(isPossible(weights,mid,days,N)){
                ans = mid;
               
                hi = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};