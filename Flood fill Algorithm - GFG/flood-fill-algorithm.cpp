//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        int startingColor = image[sr][sc];
       
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
         
            q.pop();
          
            for(int k=0; k<4; k++){
                int nrow = r+drow[k];
                int ncol = c+dcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==startingColor && startingColor!=color){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends