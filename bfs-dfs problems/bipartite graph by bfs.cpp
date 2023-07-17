class Solution {
public:
bool check(int start,vector<int> adj[],vector<int>&color)
{
    queue<int>q;
	    q.push(start);
	    
	    color[start]=0;
	    
	    while(!q.empty())
	    {
	        int u=q.front();
	        q.pop();
	        for(auto x:adj[u])
	        {
	            if(color[x]==-1)
	            {
	                color[x]=!color[u];
	                
	                
	                q.push(x);
	            }
	            else
	            {
	                if(color[x]==color[u])
	                return false;
	            }
	            
	        }
	    }
	    return true;
    
    
    
}
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int>color(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {    
	        if(color[i]==-1)
	        { 
	            bool a=check(i,adj,color);
	            if(a==false) return false;
	        }
	    }
	    return true;
	}

};