//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int cntfresh=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
              
                if(grid[i][j]==1) cntfresh++;
            }
        }
        int tm=0;
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
           
            for(int k=0; k<4; k++){
                int nrow = r+drow[k];
                int ncol = c+dcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    // grid[nrow][ncol] = 2;
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                    cntfresh--;
                }
            }
        }
       
        if(cntfresh!=0) return -1;
        
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends