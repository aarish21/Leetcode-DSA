class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int i=0,j=0,row=matrix.size(),col=matrix[0].size();

        while(i<row && j<col){
            
            int x=j;
            while(x<col){
                output.push_back(matrix[i][x]);
                x++;  
            }
            i++;
            
            x=i;
            while(x<row ){
                output.push_back(matrix[x][col-1]);
                x++;
            }
            col--;
            
            
            x=col-1;
            while(x>=j && i<row)
            {
                output.push_back(matrix[row-1][x]);
                x--;
            }
            row--;
            
            x=row-1;
           
            while(x>=i && j<col)
            {
                output.push_back(matrix[x][j]);
                x--;
            }
            j++;
        }

        return output;
    }
};