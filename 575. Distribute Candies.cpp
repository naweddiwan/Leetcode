int distributeCandies(vector<int>& candies) {
      set<int> m;
      for(auto it :candies)
         m.insert(it);
      return min(candies.size()/2, m.size());
}
