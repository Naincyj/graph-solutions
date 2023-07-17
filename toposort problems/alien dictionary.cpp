//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int>adj[K];
        
          for(int i=1;i<N;i++)
          {
               int a=dict[i-1].size();
               int b=dict[i].size();
               
               for(int k=0;k<(a>b?b:a);k++)
               {
                   if(dict[i-1][k]!=dict[i][k])
                    {adj[dict[i-1][k]-'a'].push_back(dict[i][k]-'a');
                    break;}
               }
          }
          vector<int>vis(K,0);
        vector<int>indeg(K,0);
        
        for(int i=0;i<K;i++)
        {
            for(auto x:adj[i])
             {
                 indeg[x]++;
             }
        }
        
        queue<int>q;
        
        for(int i=0;i<K;i++)
        if(indeg[i]==0)
        {
            vis[i]=true;
            q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);
            
            for(auto x:adj[u])
            {
                if(!vis[x]){
                    indeg[x]--;
                    if(indeg[x]==0)
                    {
                        q.push(x);
                        vis[x]=true;
                    }
                }
            }
        }
          
          
          
          string res="";
        
        
        
        
        
        for(int i=0;i<ans.size();i++)
        {
          res+=char('a'+ans[i]);
           
        }
        
        return res;
        
          
          
          
          
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends