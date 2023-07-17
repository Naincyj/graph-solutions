void dfs(int node,vector<int>&ans,vector<int>&vis,vector<int>adj[])
    {
        vis[node]=true;
        ans.push_back(node);
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                dfs(x,ans,vis,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
         vector<int>ans;
         vector<int>vis(V,0);
         dfs(0,ans,vis,adj);
         return ans;
    }