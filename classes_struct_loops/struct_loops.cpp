// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

#include <bits/stdc++.h>
using namespace std;

/*
class two
{
public:
    int index, value;
};
*/

typedef struct
{
    int index, value;
} two;

class Solution
{
private:
    two *array;
    int i, j, rank;

public:
    vector<int> replaceWithRank(vector<int> &arr, int n)
    {
        array = new two[n];
        rank = 1;

        for (i = 0; i < n; array[i] = {i, arr[i++]})
            ;

        sort(array, array + n, [](two a, two b)
             { return a.value < b.value; });

        j = 0;

        for (i = 0; i < n; i = j, rank++)
            for (j = i; j < n && array[j].value == array[i].value; arr[array[j++].index] = rank)
                ;

        return arr;
    }
};

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec, n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
