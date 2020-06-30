vector<string> commonChars(vector<string> &A)
{
    vector<map<char, int>> m(A.size());
    int i = 0;
    map<char, int> s;
    vector<string> res;
    for (auto strings : A)
    {
        for (auto k : strings)
        {
            s[k]++;
            (m[i])[k]++;
        }
        i++;
    }

    int min1 = INT_MAX;
    for (auto it : s)
    {
        for (auto i : m)
        {
            min1 = min(min1, i[it.first]);
        }

        while (min1--)
        {
            string s1;
            s1 += it.first;
            res.push_back(s1);
        }
        min1 = INT_MAX;
    }
    return res;
}
