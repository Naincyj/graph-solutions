//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool ispossible(int i,int j,int n,int m)
    {
        if(i<0||i>=n||j<0||j>=m) return false;
        return true;
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<int,int>>q;
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    
	     for(int i=0;i<n;i++)
	     {
	         for(int j=0;j<m;j++)
	         {
	             if(!vis[i][j]&&grid[i][j]==1)
	             {
	                 vis[i][j]=true;
	                 q.push({i,j});
	             }
	         }
	     }
	     
	     while(!q.empty())
	     {
	         int u=q.front().first;
	         int v=q.front().second;
	         q.pop();
	         
	         for(int k=0;k<4;k++)
	         {
	             if(ispossible(u+dx[k],v+dy[k],n,m))
	         {
	             if(!vis[u+dx[k]][v+dy[k]]&&grid[u+dx[k]][v+dy[k]]==0)
	             {
	                 vis[u+dx[k]][v+dy[k]]=true;
	                 q.push({u+dx[k],v+dy[k]});
	                 ans[u+dx[k]][v+dy[k]]=ans[u][v]+1;
	             }
	             
	         }
	         }
	     }
	     
	     
	     return ans;
	     
	     
	     
	     
	     
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends