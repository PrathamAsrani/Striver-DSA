#include <bits/stdc++.h>
using namespace std;

class priorityQueue
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
    void ShiftUp(int i)
    {
        while (i > 0 && arr[i] > arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void ShiftDown(int i)
    {
        int maxElementIdx = i;

        int left = leftChild(i);
        if (left < arr.size() && arr[left] > arr[maxElementIdx])
            maxElementIdx = left;

        int right = rightChild(i);
        if (right < arr.size() && arr[right] > arr[maxElementIdx])
            maxElementIdx = right;

        if (i != maxElementIdx)
        {
            swap(arr[i], arr[maxElementIdx]);
            ShiftDown(maxElementIdx);
        }
    }

public:
    void insert(int ele)
    {
        arr.push_back(ele);
        ShiftUp(arr.size()-1);
    }

    int extractMax(){
        if(arr.empty())
            return -1;
        int res = arr[0];
        arr.erase(arr.begin());
        ShiftDown(0);
        return res;
    }

    int top(){
        return arr.empty() == true ? -1 : arr[0];
    }

    void display();
};

void priorityQueue :: display(){
    for(auto i:arr)
        cout << i << " ";
    cout << "\n";
}

int main(){
    priorityQueue *pq = new priorityQueue();
    pq->insert(32);
    cout << "Inserted 32"<<endl;
    pq->insert(84);
    cout << "Inserted 84"<<endl;
    pq->insert(4);
    pq->insert(3);
    pq->insert(1);
    pq->insert(5);
    pq->insert(6);
    pq->display();
    cout << "max element extracted: " << pq->extractMax() << "\n"; 
    pq->display();
}