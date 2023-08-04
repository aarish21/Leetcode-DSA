class Solution {
    bool color(int node,vector<vector<int>> graph,int col,vector<int> &vis){
        vis[node] = col;
        for(int i=0;i<graph[node].size();i++){
            if(vis[graph[node][i]]==-1){
                if(color(graph[node][i],graph,!col,vis)==false) return false;
            }else if(col==vis[graph[node][i]]){
                return false;
            }
        }
        return true;
        
        
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
         vector<int> vis(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if(color(i,graph,0,vis)==false){
                    return false;
                }
            }
        }
        return true;
    }
};