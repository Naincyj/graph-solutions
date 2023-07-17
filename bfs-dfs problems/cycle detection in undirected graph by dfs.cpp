class Solution {
  public:
    // Function to detect cycle in an undirected graph.
bool dfs(int node,int prev,vector<int>&vis,vector<int>adj[])
{
    vis[node]=true;
    
    for(auto x:adj[node])
    {
        if(!vis[x])
        {
            if(dfs(x,node,vis,adj))
             return true;
        }
        else
        {
            if(x!=prev)
            return true;
        }
    }
    
    return false;
}
    
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
           vector<int>vis(V,0);
           for(int i=0;i<V;i++)
           {
               if(!vis[i])
               {
                   if(dfs(i,-1,vis,adj)==true)
                   return true;
               }
           }
           
           return false;
    }
};