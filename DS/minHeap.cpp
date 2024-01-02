#include <bits/stdc++.h>

using namespace std;

class SeatManager
{
    int num = 1;
    priority_queue<int, vector<int>, greater<>> min_heap;
public:
    SeatManager(int limit) {}

    int reserve()
    {
        if (min_heap.empty())
            return num++;
        int d = min_heap.top();
        min_heap.pop();
        return d;
    }

    void unreserve(int s)
    {
        min_heap.push(s);
    }
};

int main () 
{ 
    // Creates a min heap 
    priority_queue <int, vector<int>, greater<int> > pq; 
    pq.push(5); 
    pq.push(1); 
    pq.push(10); 
    pq.push(30); 
    pq.push(20); 
  
    // One by one extract items from min heap 
    while (pq.empty() == false) 
    { 
        cout << pq.top() << " "; 
        pq.pop(); 
    } 
  
    return 0; 
} 
