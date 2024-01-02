#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> vec(3, vector<int> (3, -1));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
