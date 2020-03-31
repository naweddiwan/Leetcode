vector<int> dailyTemperatures(vector<int> &T)
{
    vector<int> res(T.size(), 0);
    stack<pair<int, int>> s;
    s.push(make_pair(T[0], 0));
    int i = 1;
    while (i < T.size())
    {
        while ((T[i] > (s.top()).first))
        {
            pair<int, int> temp = s.top();
            s.pop();
            res[temp.second] = i - temp.second;

            if (s.empty())
                break;
        }
        if (s.empty())
        {
            s.push(make_pair(T[i], i));
            i++;
        }
        else if (T[i] <= (s.top()).first && !s.empty())
        {
            s.push(make_pair(T[i], i));
            i++;
        }
    }
    return res;
}
