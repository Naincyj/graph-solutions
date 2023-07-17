vector<int> bfsOfGraph(int V, vector<int> adj[]) {
         vector<int>ans;
         queue<int>q;
         q.push(0);
         vector<int>vis(V);
         vis[0]=true;
         
         while(!q.empty())
         {
             int u=q.front();
             q.pop();
             ans.push_back(u);
             for(auto x:adj[u])
             {
                 if(!vis[x])
                 {
                     vis[x]=true;
                     q.push(x);
                 }
             }
         }
         
         return ans;
    }