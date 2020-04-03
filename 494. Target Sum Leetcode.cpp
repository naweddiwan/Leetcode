 int help(vector<int> nums, int curr, int ind, int target,  map<pair<int, int>, int> &m)
    {
       if(m.find({curr,ind})!=m.end())
           return m[make_pair(curr, ind)];
        if(curr==target && ind == nums.size())
        {
            return 1; 
        }
        if(ind >= nums.size())
            return 0;
        
       m[{curr, ind}] = help(nums, curr+nums[ind], ind+1, target,m)+help(nums, curr-nums[ind], ind+1, target,m);
        
       return m[make_pair(curr, ind)];
    }
    
    
    int findTargetSumWays(vector<int>& nums, int S) {
        map<pair<int, int>, int> m;
       return help(nums, 0, 0, S, m);
    }
