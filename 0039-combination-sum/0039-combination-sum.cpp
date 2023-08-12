class Solution {
    void solve(int i,vector<int>& arr, int k,int sum,vector<vector<int>> &ans,vector<int> s){
        if(i>=arr.size() || sum>k) return;
       
        if(sum==k){
            ans.push_back(s);
            return;
        }
        s.push_back(arr[i]);
        solve(i,arr,k,sum+arr[i],ans,s);
        s.pop_back();
        solve(i+1,arr,k,sum,ans,s);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> s;
        solve(0,candidates,target,0,ans,s);
        return ans;
    }
};