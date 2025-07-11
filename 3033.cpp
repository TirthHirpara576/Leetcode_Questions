class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> answer = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1){
                    int max = INT_MIN;
                    for(int k=0;k<m;k++){
                        if(matrix[k][j] > max){
                            max = matrix[k][j];
                        }
                    }
                    answer[i][j] = max;
                }
            }
        }
        return answer;
    }
};