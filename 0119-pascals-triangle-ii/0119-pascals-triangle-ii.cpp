class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r(rowIndex+1);
        r[0]=r[rowIndex]=1;
        for(int i=1;i<rowIndex;i++){
            int j=i;
            double sum = 1;
  
            for(int j = 1; j <= i; j++){
                sum = sum * (rowIndex - i + j) / j;
            }
            r[i]=sum;
            
        }
       
        return r;
    }
};