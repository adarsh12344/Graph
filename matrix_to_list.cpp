#include<bits/stdc++.h>
using namespace std;
int matrix(vector<vector<int>>adjmatrix,int V)
{
    vector<int>adjlist[V];
    for(int i=0;i<V;i++)     //here we are converting matrix to list
    {
        for(int j=0;j<V;j++)
        {
            if(adjmatrix[i][j]==1)
            {
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }
    return 0;
}
