//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool ispossible(int i,int j,int n,int m)
    {
        if(i<0||i>=n||j<0||j>=m) return false;
        return true;
    }
    
    
    
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
           queue<pair<int,int>>q;
           int time=-1;
           int n=grid.size();
           int m=grid[0].size();
           
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++)
               {
                   if(grid[i][j]==2)
                   q.push({i,j});
               }
           }
           
           while(!q.empty())
           {
               int b=q.size();
               time++;
               while(b--)
               {
                   int u=q.front().first;
                   int v=q.front().second;
                   q.pop();
                   
                   for(int k=0;k<4;k++)
                   {
                       if(ispossible(u+dx[k],v+dy[k],n,m))
                       {
                           if(grid[u+dx[k]][v+dy[k]]==1)
                           {
                               grid[u+dx[k]][v+dy[k]]=2;
                               q.push({u+dx[k],v+dy[k]});
                           }
                       }
                   }
               }
           }
           
           
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++)
               {
                   if(grid[i][j]==1)
                   return -1;
               }
           }
           
           
           
           return time;
           
           
           
           
           
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends