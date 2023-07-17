class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int node,vector<int>&vis,stack<int>&stk,vector<int>adj[])
	{
	    vis[node]=true;
	    
	    for(auto x:adj[node])
	    {
	        if(!vis[x])
	        dfs(x,vis,stk,adj);
	    }
	    
	    stk.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	     stack<int>stk;
	     vector<int>ans;
	     vector<int>vis(V,0);
	      for(int i=0;i<V;i++)
	      {
	          if(!vis[i])
	          dfs(i,vis,stk,adj);
	      }
	      while(!stk.empty())
	      {
	          ans.push_back(stk.top());
	          stk.pop();
	      }
	      return ans;
	}
};