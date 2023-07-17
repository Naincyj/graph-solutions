class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<int>adj[])
    {
        vis[node]=true;
        pathvis[node]=true;
        
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                if(dfs(x,vis,pathvis,adj))
                return true;
            }
            else
            {
                if(pathvis[x]==true)
                 return true;
            }
        }
        
        
        pathvis[node]=false;
        return false;
    }
    
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>pathvis(V,0);
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathvis,adj))
                return true;
            }
        }
        
        return false;
    }
};