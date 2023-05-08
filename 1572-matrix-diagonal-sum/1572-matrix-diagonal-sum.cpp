class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0,n=mat.size();
        for(int i=0;i<mat.size();i++){
            sum+=mat[i][i];
            sum+=mat[n-1-i][i];
        }
        if(mat.size()%2==1) sum-=mat[n/2][n/2];
        return sum;
    }
};