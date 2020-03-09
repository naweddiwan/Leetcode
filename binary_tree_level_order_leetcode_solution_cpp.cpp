void helper(map<int, vector<int>> &m, TreeNode *root)
    {
      if(root==NULL)
          return;
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        while(q.size()>0)
        {
            pair<TreeNode*, int> front;
            front =q.front();
            q.pop();
            if((front.first)->left)
            {
                q.push(make_pair((front.first)->left, front.second+1));
            }
            if((front.first)->right)
                q.push(make_pair((front.first)->right, front.second+1));
            m[front.second].push_back(front.first->val);
        }
        
    }
    vector<vector<int>> levelOrder(TreeNode* root)
    {
       
         map<int, vector<int> > m;
        
            
        helper(m,root);
        
        int n =m.size();
        vector<vector<int>> res(n);
        for(auto it:m)
        {
            res[it.first] = it.second;
        }
        return res;
        
    }
