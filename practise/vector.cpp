#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mat[3][4] = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {1, 2, 3, 4}};
    set<vector<int>> s;
    for (int i = 0; i < 3; i++)
    {
        vector<int> t;
        for (int j = 0; j < 4; j++)
        {
            t.push_back(mat[i][j]);
        }
        s.insert(t);
    }
    vector<vector<int>> v;
    for (vector<int> itr : s)
    {
        v.push_back(itr);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[0] != v[1])
            cout << "not equal\n";
        for (int j = 0; j < 4; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    int size = sizeof(mat) / sizeof(mat[0][0]);
    vector<vector<int>> vec(mat, size + mat);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << v[i][j] << " ";
        }
    }
    for (vector<int> itr : v)
    {
        for (int i = 1; i < v.size(); i++)
        {
            if (itr == v[i])
            {
                v.erase(v.begin() + i, v.begin() + i + 1);
            }
        }
    }

    
}