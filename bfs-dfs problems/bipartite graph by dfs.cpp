//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int node,int color,vector<int>&vis,vector<int>adj[])
    {
        vis[node]=color;
        
        for(auto x:adj[node])
        {
            if(vis[x]==2)
            {
                if(dfs(x,!color,vis,adj)==false)
                 return false;
                 
            }
            else
            {
                if(vis[x]==vis[node])
                return false;
                
                
            }
        }
        
        
        return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	     vector<int>vis(V,2);
	      
	      for(int i=0;i<V;i++)
	      {
	          if(vis[i]==2)
	          {
	              if(dfs(i,0,vis,adj)==false)
	              return false;
	          }
	      }
	      
	      return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends