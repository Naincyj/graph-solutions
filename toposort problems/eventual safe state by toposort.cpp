class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int>adjrev[V];
        
        
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                adjrev[x].push_back(i);
            }
        }
        
        vector<int>indeg(V,0);
        vector<int>vis(V,0);
        queue<int>q;
        
        for(int i=0;i<V;i++)
        {
            for(auto x:adjrev[i])
            {
                indeg[x]++;
            }
        }
        
        for(int i=0;i<V;i++)
        if(indeg[i]==0)
          {q.push(i);
          vis[i]=true;}
          
          vector<int>ans;
          
          while(!q.empty())
          {
              int u=q.front();
              q.pop();
              
              for(auto x:adjrev[u])
              {
                  if(!vis[x])
                  {
                      indeg[x]--;
                      if(indeg[x]==0)
                      {
                          q.push(x);
                          vis[x]=true;
                      }
                  }
              }
              
          }
          
          for(int i=0;i<V;i++)
          if(indeg[i]==0)
            ans.push_back(i);
          
          
          
          return ans;
        
        
        
        
        
        
    }
};