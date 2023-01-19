class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> front(n,0),cur(n,0);
        for(int j=0;j<n;j++) front[j] = matrix[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int d = matrix[i][j]+front[j];
                int diaR = INT_MAX;
                if(j<n-1)
                diaR = matrix[i][j]+front[j+1];
                int diaL = INT_MAX;
                if(j>0)
                diaL = matrix[i][j]+front[j-1];
                cur[j] = min(d,min(diaL,diaR));
            }
            front = cur;
        }
        int mini = INT_MAX;
    
        for(int j=0; j<n;j++){
            mini = min(mini,front[j]);
        }
        return mini;
    }
};