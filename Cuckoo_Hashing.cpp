#include <bits/stdc++.h>
using namespace std;

vector<int> table1, table2;
int mod, flag = -1, call = 1;

int hash_key(int fun, int key);
void hashKeys(vector<int> &arr);
void placeEle(int e, int i);
void printHashTable();

int main()
{
    int n;
    // cin >> n;

    // vector<int> arr(n);
    // for (auto &i : arr)
    //     cin >> i;

    vector<int> arr = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
    n = arr.size();
    table1.resize(n, -1);
    table2.resize(n, -1);
    mod = n;
    hashKeys(arr);
    printHashTable();
}

int hash_key(int fun, int key)
{
    switch (fun)
    {
    case 1:
        return key % mod;
        break;

    case 2:
        return (key / mod) % mod;
        break;

    default:
        break;
    }
}

void hashKeys(vector<int> &arr)
{
    for (auto ele : arr)
    {
        int pos = hash_key(1, ele);
        if (table1[pos] == flag)
            table1[pos] = ele;
        else if (table2[hash_key(2, table1[pos])] == flag)
        {
            table2[hash_key(2, table1[pos])] = table1[pos];
            table1[pos] = ele;
        }
        else
        {
            call = 2;
            placeEle(ele, pos);
        }
    }
}

void placeEle(int e, int i)
{
    if(table1[i] == -1){
        table1[i] = e;
        return ;
    }
    if(table2[i] == -1){
        table2[i] = e;
        return ;
    }
    int tmp = table1[i];
    table1[i] = e;
    i = hash_key(call, tmp);
    if (call == 2)
        call = 1;
    else
        call = 2;
    placeEle(tmp, i);
}

void printHashTable(){
    cout << "Table1: \n";
    for(auto i:table1)
        cout << i << " ";
    cout << "\n\n";
    cout << "Table2: \n";
    for(auto i:table2)
        cout << i << " ";
    cout << "\n";
}