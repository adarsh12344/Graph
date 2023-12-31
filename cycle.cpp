#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool solve(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
  
  
  public:

    bool isCycle(int V, vector<int> adj[]) {
    
        int vis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(solve(i, adj, vis) == true){
                    return true;
                }
            }
        }
        return false;
    }
};