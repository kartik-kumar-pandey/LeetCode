class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        
        if(m*n!=r*c){
            return mat;
        }

        if(m==r&&n==c){
            return mat;
        }

        vector<int>nums;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums.push_back(mat[i][j]);
            }
        }

        vector<vector<int>> ret(r,vector<int>(c));
        int k=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ret[i][j]=nums[k++];
            }
        }
        
        return ret;
    }
};   