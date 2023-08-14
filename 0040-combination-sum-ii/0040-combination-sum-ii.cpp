class Solution {
    void solve(int i, vector<int>& arr, int k, int sum, vector<vector<int>>& ans, vector<int> s) {
        if (sum == k) {
            ans.push_back(s);
            return;
        }
        if (i== arr.size()){
             return;
        } 
          
        if(sum>k){
            return;
        }

        s.push_back(arr[i]);
        solve(i + 1, arr, k, sum + arr[i], ans, s);
        s.pop_back();
        // sum-=arr[i];
        while (i+1< arr.size() && arr[i] == arr[i + 1]) {
            i++;
        }
        solve(i + 1, arr, k, sum, ans, s);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> s;
        solve(0, candidates, target, 0, ans, s);
        return ans;
    }
};
