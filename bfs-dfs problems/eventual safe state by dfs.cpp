class Solution {
  public:
  bool dfs(int node,vector<int> adj[],vector<int>&vis,vector<int>&pathvis)
  {
      vis[node]=1;
      pathvis[node]=1;
      
      for(auto x:adj[node])
      {
          if(!vis[x])
          {
              if(dfs(x,adj,vis,pathvis)==true)
              return true;
          }
          else
          {
              if(pathvis[x]==1) return true;
          }
      }
      
      
      
      pathvis[node]=0;
      return false;
      
      
      
      
  }
  
  
  
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,pathvis);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++)
        if(pathvis[i]==0) ans.push_back(i);
        
        return ans;
    }
};