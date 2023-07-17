//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool ispossible(int i,int j,int n,int m)
    {
        if(i<0||i>=n||j<0||j>=m) return false;
        return true;
    }
void dfs(int i,int j,vector<vector<int>>& image,vector<vector<int>>& vis,int start_color,int newColor,int n,int m)
{
    vis[i][j]=true;
    
    image[i][j]=newColor;
    
    for(int k=0;k<4;k++)
    {
        int u=i+dx[k];
        int v=j+dy[k];
        
        if(ispossible(u,v,n,m))
        {
            if(!vis[u][v]&&(image[u][v]==start_color))
            {
                dfs(u,v,image,vis,start_color,newColor,n,m);
            }
        }
    }
    
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         
          int n=image.size();
          int m=image[0].size();
          int start_color=image[sr][sc];
          
          vector<vector<int>>vis(n,vector<int>(m,0));
          
          dfs(sr,sc,image,vis,start_color,newColor,n,m);
          
          return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends