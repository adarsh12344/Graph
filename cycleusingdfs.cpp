#include<bits/stdc++.h>

using namespace std;

bool cycle(int node , int parent , vector<int>adj[], int vis[])
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            if(cycle(it , node , adj ,vis)==true)
            {
                return true;
            }
            else if(it!=parent)
            {
                return true;
            }

        }    
}

    return false;
}





bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(cycle(i , -1 , adj , vis)==true)
            {
                return true;
            }
        }
    }
    return false;
}