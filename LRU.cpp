//{ Driver Code Starts 
// https://www.geeksforgeeks.org/problems/lru-cache/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> umpp;
    int size;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        size = cap;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        if (umpp.find(key) != umpp.end())
        {
            // tranfer key to most recently used
            li.splice(li.begin(), li, umpp[key]);
            return umpp[key]->second;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (umpp.find(key) != umpp.end())
        {
            li.splice(li.begin(), li, umpp[key]);
            umpp[key]->second = value;
            return;
        }
        if (li.size() == size)
        {
            int del = li.back().first;
            li.pop_back();
            umpp.erase(del);
        }
        li.push_front({key, value});
        umpp[key] = li.begin();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends