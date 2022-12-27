class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        int count=0;
        vector<int> diff(rocks.size());
        for(int i=0;i<capacity.size();i++){
            int d = capacity[i]-rocks[i];
            diff[i] = d;
        }
        sort(diff.begin(), diff.end());
        for(int i=0;i<capacity.size();i++){
            if(ar == 0)
                break;
            if(diff[i]==0){
                count++;
                continue;
            }
            if(ar>=diff[i]) {
                ar-=diff[i];
                diff[i] = 0;
                count++;
            }
            
            
        }
        return count;
    }
};