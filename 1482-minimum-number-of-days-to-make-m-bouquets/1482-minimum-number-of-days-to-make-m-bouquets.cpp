class Solution {
public:
    bool isPossible(vector<int> A,int mid,int M,int k){
        int tot = 0,c = 0;
        for(int i=0;i<A.size();i++){
            if(A[i]<=mid) {
                c++;
                if(c==k){
                    tot++;
                    c=0;
                }
            }
            else
                c=0;
        }
        return tot>=M;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0,hi = INT_MAX-1,ans = -1;
        while(low<=hi) {
            int mid = low+(hi-low)/2;
            if(isPossible(bloomDay,mid,m,k)){
                ans = mid;
               
                hi = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};