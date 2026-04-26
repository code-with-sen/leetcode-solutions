// 1559. Detect Cycles in 2D Grid [Medium]
// https://leetcode.com/problems/detect-cycles-in-2d-grid/
// Language: C++ | Runtime: 23 ms | Memory: 68.8 MB

class Solution {
public:
    using pp=pair<int,int>;
    vector<pp>dir={{1,0},{-1,0},{0,1},{0,-1}};

    int m,n;

    bool dfs(int sx,int sy,int px,int py,vector<vector<char>>&grid,vector<vector<bool>>& vis){

        vis[sx][sy]=true;

        // cout<<"sx:"<<sx<<" "<<"sy:"<<sy<<endl;
        // cout<<"px:"<<px<<" "<<"py:"<<py<<endl;

        for(auto d:dir){
            int nx=sx+d.first;
            int ny=sy+d.second;
            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==grid[sx][sy]){
                if(nx!=px || ny!=py){
                    if(vis[nx][ny]) return true;
                    if(dfs(nx,ny,sx,sy,grid,vis)) return true;
                }
            }
        }

        return false;

    }

    bool containsCycle(vector<vector<char>>& grid) {

        m=grid.size();
        n=grid[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j]) {
                    if(dfs(i,j,-1,-1,grid,vis)) return true;
                    // cout<<endl;
                }
            }
        }

        return false;
    }
};


// ["c","a","d"],
// ["a","a","a"],
// ["a","a","d"],
// ["a","c","d"],
// ["a","b","c"]

// d u r l
