vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n= mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++)
        {
            int k=i,j=0;
            vector<int> temp;
            while(k<n && j<m)
            {
                 temp.push_back(mat[k][j]);
                k++;
                j++;
            
            }
            sort(temp.begin(), temp.end());
            k=i;
            j=0;
            while(k<n && j<m)
            {
                mat[k][j] =temp[j];
                j++;
                k++;
            }
            
        }
        for(int i=1; i<m; i++)
        {
            int k=0,j=i;
            vector<int> temp;
            while(k<n && j<m)
            {
                 temp.push_back(mat[k][j]);
                k++;
                j++;
            
            }
            sort(temp.begin(), temp.end());
            k=0;
            j=i;
            while(k<n && j<m)
            {
                mat[k][j] =temp[k];
                j++;
                k++;
            }
            
        }
        return mat;
    }
