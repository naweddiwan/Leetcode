vector<string> parser(string my_str, char c)
{
    vector<string> result;
    stringstream s_stream(my_str);
    while (s_stream.good())
    {
        string substr;
        getline(s_stream, substr, c);
        result.push_back(substr);
    }

    return result;
}
vector<string> subdomainVisits(vector<string> &cpdomains)
{

    map<string, int> m;
    vector<string> tokens;
    for (int i = 0; i < cpdomains.size(); i++)
    {
        cout << i + 1 << endl;

        vector<string> temp = parser(cpdomains[i], ' ');
        int count = stoi(temp[0]);
        string s1 = temp[1];

        vector<string> temp2 = parser(s1, '.');

        if (temp2.size() == 3)
        {
            string s2 = temp2[1] + "." + temp2[2];
            string s3 = temp2[2];
            m[s1] += count;
            m[s2] += count;
            m[s3] += count;
        }
        else if (temp2.size() == 2)
        {
            string s2 = temp2[1];
            m[s1] += count;
            m[s2] += count;
        }
    }
    for (auto it : m)
    {
        tokens.push_back(to_string(it.second) + " " + it.first);
    }
    return tokens;
}
