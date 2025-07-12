class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        bool flag = true;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==j || i+j==m-1){ // Diagonal
                    if(grid[i][j] == 0){
                        flag=false;
                    }
                }
                else{   // Non-Diagonal
                    if(grid[i][j] != 0){
                        flag=false;
                    }
                }
            }
        }
        return flag;
    }
};