//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool ispossible(int i,int j,int n,int m)
    {  if(i<0||i>=n||j<0||j>=m) return false;
       return true;
        
    }
    
    int dx[8]={1,0,-1,0,1,1,-1,-1};
    int dy[8]={0,1,0,-1,1,-1,1,-1};
    
    
void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid,int n,int m)
{ 
    vis[i][j]=true;
    
    
    for(int k=0;k<8;k++)
    {
        int u=i+dx[k];
        int v=j+dy[k];
        
        if(ispossible(u,v,n,m))
        {
            if(!vis[u][v]&&grid[u][v]=='1')
            {
                dfs(u,v,vis,grid,n,m);
            }
        }
    }
    
    
}
    
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid,int n,int m)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=true;
        
         while(!q.empty())
         {
             int a=q.front().first;
             int b=q.front().second;
             q.pop();
             
             
             for(int k=0;k<8;k++)
             { int u=a+dx[k];
        int v=b+dy[k];
        
        if(ispossible(u,v,n,m))
        {
            if(!vis[u][v]&&grid[u][v]=='1')
            {
                vis[u][v]=true;
                q.push({u,v});
            }
        }
                 
             }
         }
         
         
    }
    
    
    
    
    int numIslands(vector<vector<char>>& grid) {
           int n=grid.size();
           int m=grid[0].size();
           
           vector<vector<int>>vis(n,vector<int>(m,0));
           
           int cnt=0;
           
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++)
               {
                   if(!vis[i][j]&&grid[i][j]=='1')
                   {   
                       cnt++;
                       bfs(i,j,vis,grid,n,m);
                   }
               }
           }
           
           return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends