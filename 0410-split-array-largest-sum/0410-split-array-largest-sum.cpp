class Solution {
public:
//     bool isPossible(vector<int> A,int mid,int M,int N){
//         int allocatedStu = 1,pages = 0;
//         for(int i=0;i<N;i++){
//             if(A[i]>mid) return false;
//             if(pages+A[i]>mid){
//                 allocatedStu+=1;
//                 pages=A[i];
//             }else
//                 pages+=A[i];
//         }
//         return allocatedStu<=M;
//     }
//     int splitArray(vector<int>& nums, int k) {
//         int N = nums.size();
//         if(N<k) return -1;
//         int sum=0,maxN=0;
//         for(int i=0;i<N;i++){
//             sum+=nums[i];
//             maxN = max(maxN,nums[i]);
//         }
//         int low = maxN,hi = sum,ans = -1;
//         while(low<=hi) {
//             int mid = (low+hi)/2;
//             if(isPossible(nums,mid,k,N)){
//                 ans = mid;
               
//                 hi = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     }
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=0,n=nums.size();
        for(int i=0;i<n;++i) l=max(l,nums[i]), r+=nums[i];
        
        int mid=0,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            int count=0,tempsum=0;
            for(int i=0;i<n;++i){
                if(tempsum+nums[i]<=mid) tempsum+=nums[i];
                else count++,tempsum=nums[i];
            }
            count++; 
            
            if(count<=m) r=mid-1, ans=mid;
            else l=mid+1;
        }  
        return ans;
    }
};