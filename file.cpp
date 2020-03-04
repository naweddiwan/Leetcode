#include <bits/stdc++.h>
using namespace std;
#define ll long long
void merge(vector<string> &arr, ll l, ll m, ll r)
{
    ll i, j, k;
    ll n = r - l + 1;
    vector<string> temp(n);
    i = l;
    j = m + 1;
    k = 0;
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = temp[i - l];
}
void merge_sort(vector<string> &arr, ll l, ll r)
{
    ll m;
    if (l < r)
    {
        m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    // Enter code
    ifstream fin;
    vector<string> arr;
    fin.open("test_input.txt");
    // Execute a loop until EOF (End of File)
    while (fin)
    {
        string line;
        getline(fin, line);
        if (line != "") // excluding blank lines
            arr.push_back(line);
    }
    ll n = arr.size();
    merge_sort(arr, 0, n - 1);
    ofstream fout;
    fout.open("result.txt");
    ll i = 0;
    while (fout && i < n)
    {
        fout << arr[i++] << endl;
    }

    fout.close();
    fin.close();

    return 0;
}