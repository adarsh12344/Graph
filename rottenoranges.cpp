//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
 
    public:
    //Function to find minimum time required to rot all oranges. 
     int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){    //here we are pushing all the rotten oranges in the queue
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }

            }
        }
        int tm = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while(!q.empty()){    //here we are doing bfs traversal
            int r = q.front().first.first;         //here we are storing the row and column of the rotten oranges
            int c = q.front().first.second;       
            int t = q.front().second;           //here we are storing the time taken to rot the oranges
            tm = max(tm, t);                 //here we are storing the maximum time taken to rot the oranges
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
            
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    return -1;
                }
            }
        }
        return tm;
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