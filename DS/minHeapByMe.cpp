#include <bits/stdc++.h>

using namespace std;

class min_heap
{
    vector<int> arr;
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int leftChild(int i)
    {
        return 2 * i + 1;
    }
    int rightChild(int i)
    {
        return 2 * i + 2;
    }
    void SwiftUp(int i)
    {
        while (i > 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void SwiftDown(int i)
    {
        int mini = i;
        int left = leftChild(i);
        int right = rightChild(i);

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
    void insert(int ele){
        arr.push_back(ele);
        SwiftUp(arr.size()-1);
    }

    int top(){
        return arr[0];
    }

    int extractMIN(){
        if(arr.empty())
            return -1;
        int minEle=top();
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        SwiftDown(0);
        return minEle;
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