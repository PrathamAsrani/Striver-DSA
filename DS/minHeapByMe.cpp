#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class min_heap
{
    vector<ll> arr;
    ll parent(ll i)
    {
        return (i - 1) / 2;
    }
    ll leftChild(ll i)
    {
        return 2 * i + 1;
    }
    ll rightChild(ll i)
    {
        return 2 * i + 2;
    }
    void SwiftUp(ll i)
    {
        while (i > 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void SwiftDown(ll i)
    {
        ll mini = i;
        ll left = leftChild(i);
        ll right = rightChild(i);

        if (left < arr.size() && arr[left] < arr[mini])
            mini = left;

        if (right < arr.size() && arr[right] < arr[mini])
            mini = right;

        if (mini != i)
        {
            swap(arr[i], arr[mini]);
            SwiftDown(mini);
        }
    }

public:
    void insert(ll ele){
        arr.push_back(ele);
        SwiftUp(arr.size()-1);
    }

    ll top(){
        return arr[0];
    }

    ll extractMIN(){
        if(arr.empty())
            return -1;
        ll minEle=top();
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        SwiftDown(0);
        return minEle;
    }
    ll size(){
        return arr.size();
    }

    void display(){
        for(auto i:arr)
            cout << i << " ";
        cout << "\n";
    }
};

int main()
{
    min_heap *pq = new min_heap();
    pq->insert(5);
    pq->insert(0);
    pq->insert(2);
    pq->insert(1);
    pq->display();
    cout << "minele extract: " << pq->extractMIN() << "\n";
    pq->display();
    cout << "minele extract: " << pq->extractMIN() << "\n";
    pq->display();
}