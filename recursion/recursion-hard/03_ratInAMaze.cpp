#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string path, vector<vector<int>> &vis, int di[], int dj[]) {
    if(i == n - 1 && j == n - 1) {
        ans.push_back(path); 
        return;
    }
    string dir = "DLRU"; 
    for(int idx = 0; idx < dir.size(); idx++) {
        int next_i = i + di[idx]; // down => i + 1 - // row
        int next_j = j + dj[idx]; // down => i + 0 - // col
        if(
            next_i >= 0 && next_j >= 0 &&
            next_i < n && next_j < n && 
            !vis[next_i][next_j] && maze[next_i][next_j] == 1 
        ) {
            vis[i][j] = 1;
            solve(next_i, next_j, maze, n, ans, path + dir[idx], vis, di, dj); 
            vis[i][j] = 0;  
        }
    }
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    int n = maze.size(); 
    vector<string> ans; 
    vector<vector<int>> vis(n, vector<int> (n, 0)); 
    // DLRU
    int di[] = {+1, 0, 0, -1}; 
    int dj[] = {0, -1, +1, 0}; 
    if(maze[0][0] == 1) solve(0, 0, maze, n, ans, "", vis, di, dj);
    return ans; 
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }
    
    vector<string> result = ratInMaze(maze);
    
    for(const string& path : result) {
        cout << path << " ";
    }
    cout << endl;
    
    return 0;
}
