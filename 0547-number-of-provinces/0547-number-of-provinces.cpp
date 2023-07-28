class Solution {
public:
     
void dfs(int node,vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& roads) {
        int n=roads.size();
        vector<int> adjL[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(roads[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(i,adjL,vis);
            }
        }
        return count;
    }
};