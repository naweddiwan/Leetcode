 vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        map<int, vector<pair<int, int>>> m;
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                int dist = abs(r0- i) + abs(c0-j);
                m[dist].push_back({i,j});
            }
        }
        vector<vector<int>> res;
        {
            for(auto it:m)
            {
                for(auto it1:it.second)
                {
                    vector<int> temp(2);
                    temp[0] = it1.first;
                    temp[1] = it1.second;
                    res.push_back(temp);
                }
            }
        }
        return res;
        
    }
