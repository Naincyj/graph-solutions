class Solution {
public:
  void dfs(int node,vector<int>&vis,vector<vector<int>>&isConnected)
  {
      vis[node]=true;

        for(int i=0;i<isConnected.size();i++)
        {
              if((node!=i)&&isConnected[node][i]==1)
              {
                  if(!vis[i])
                  {
                      dfs(i,vis,isConnected);
                  }
              }
        }
  }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
       int cnt=0;
        vector<int>vis(v,0);
       for(int i=0;i<v;i++)
       {
           if(!vis[i])
           {
               cnt++;
               dfs(i,vis,isConnected);
           }
       }

       return cnt;

    }
};