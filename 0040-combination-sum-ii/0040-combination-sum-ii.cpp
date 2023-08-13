class Solution {
    void solve(int i, vector<int>& arr, int k, vector<vector<int>>& ans, vector<int> s) {
       
        if(k==0){
            ans.push_back(s);
            return;
        }
        
        for(int j=i;j<arr.size();j++){
            if(j>i && arr[j]==arr[j-1]){
                continue;
            }
            if(arr[j]>k) break;
            s.push_back(arr[j]);
            solve(j+1,arr,k-arr[j],ans,s);
            s.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> s;
        solve(0, candidates, target, ans, s);
        return ans;
    }
};
