

int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n= position.size();
        if(n==0)
            return 0;
        vector<pair<int, double>> arrival_times; // pair of initial position and arrival times
        for(int i=0; i<n; i++)
        {
            double at = (((double)target - (double)position[i])/(double)speed[i]);
            arrival_times.push_back(make_pair(position[i], at));
        }
        sort(arrival_times.begin(), arrival_times.end(), greater<>()); // sorting the position and arrival time array wrt to position in descending order
        
        int count =1; 
        double curr = arrival_times[0].second;
        for(auto it : arrival_times)
        {
            if(it.second > curr)
            {
                curr = it.second;
                count++;
            }
        }
        return count;
    }
