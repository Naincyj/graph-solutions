//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool ispossible(int i,int j,int n,int m)
    {  if(i<0||i>=n||j<0||j>=m) return false;
       return true;
        
    }
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    
void dfs(int i,int j,vector<vector<int>>&vis,vector<pair<int,int>>&ans,vector<vector<int>>&grid,int n,int m,int a,int b)
{ 
    vis[i][j]=true;
    ans.push_back({i-a,j-b});
    
    for(int k=0;k<4;k++)
    {
        int u=i+dx[k];
        int v=j+dy[k];
        
        if(ispossible(u,v,n,m))
        {
            if(!vis[u][v]&&grid[u][v]==1)
            {
                dfs(u,v,vis,ans,grid,n,m,a,b);
            }
        }
    }
    
    
}
  
  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        set<vector<pair<int,int>>>s;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]==1)
                {
                    vector<pair<int,int>>ans;
                    dfs(i,j,vis,ans,grid,n,m,i,j);
                    s.insert(ans);
                    
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends