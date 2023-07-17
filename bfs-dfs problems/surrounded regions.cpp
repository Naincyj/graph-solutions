class Solution {
public:
bool ispossible(int i,int j,int n,int m)
    {  if(i<0||i>=n||j<0||j>=m) return false;
       return true;
        
    }
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    
void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&board,int n,int m)
{ 
    vis[i][j]=true;
    
    
    for(int k=0;k<4;k++)
    {
        int u=i+dx[k];
        int v=j+dy[k];
        
        if(ispossible(u,v,n,m))
        {
            if(!vis[u][v]&&board[u][v]=='O')
            {
                dfs(u,v,vis,board,n,m);
            }
        }
    }
    
    
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            if(!vis[i][0]&&board[i][0]=='O')
            {
                dfs(i,0,vis,board,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][m-1]&&board[i][m-1]=='O')
            {
                dfs(i,m-1,vis,board,n,m);
            }
        }

      for(int j=1;j<=m-2;j++)
      {
          if(!vis[0][j]&&board[0][j]=='O')
            {
                dfs(0,j,vis,board,n,m);
            }
      }
    for(int j=1;j<=m-2;j++)
      {
          if(!vis[n-1][j]&&board[n-1][j]=='O')
            {
                dfs(n-1,j,vis,board,n,m);
            }
      }


      for(int i=1;i<n;i++)
      {
          for(int j=1;j<m;j++)
          {
              if(!vis[i][j]&&board[i][j]=='O')
              {
                  board[i][j]='X';
              }
          }
      }
      return;


    }
};