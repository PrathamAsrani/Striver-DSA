#include <bits/stdc++.h>

using namespace std;

/*
class maxHeap
{
    int *arr, n, index;
    public:
        maxHeap(){
            arr = new int[INT_MAX];
            index = 0;
            arr[0] = -1;
            n = 0;
        }
        void insert(int val){
            arr[++index] = val;
            n = index+1;
            int t = index;
            while(t > 1){
                int parentIndex = t/2;
                if(arr[parentIndex] < arr[t]) swap(arr[parentIndex], arr[t]);
                else return;
            }
        }
        void print(){
            for (int i = 1; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout <<"\n";
        }
};

int main(int argc, char const *argv[])
{
    maxHeap m;

    // m.insert(50);
    // m.insert(55);
    // m.insert(53);
    // m.insert(52);
    // m.insert(54);
    // 55 54 53 50 52

    m.insert(4);
    m.insert(1);
    m.insert(3);
    m.insert(5);
    m.insert(6);
    m.print();
    return 0;
}
*/

class maxHeap
{
private:
    int _size{};                                 // {}: initializer list // default bytes 0
    vector<int> v = {-1};                        // v[0] = -1; cause heap starts form index 1 always
    int parent(int i) { return i >> 1; }         // i/2
    int leftChild(int i) { return i << 1; }      // i*2
    int rightChild(int i) { return i << 1 + 1; } // i*2 + 1
public:
    bool isEmpty() const { return _size == 0; };
    int getMax() const { return v[1]; };
    void insertItem(int item);
    void shiftUp(int i);
    int extractMax(); // used to remove root
    void shiftDown(int i);
    void display();
};

void maxHeap::insertItem(int item)
{
    if (_size + 1 >= v.size())
    {
        v.push_back(0);
    }
    v[++_size] = item;
    shiftUp(_size);
}

int maxHeap::extractMax()
{
    int root = v[1]; // max
    swap(v[1], v[_size--]);
    shiftDown(1);
    return root;
}

void maxHeap::shiftDown(int i)
{
    if (i > _size)
        return;
    int swapId = i;
    if (leftChild(i) <= _size && v[i] < v[leftChild(i)])
        swapId = leftChild(i);
    if (rightChild(i) <= _size && v[swapId] < v[rightChild(i)])
        swapId = rightChild(i);
    if (swapId != i)
    {
        swap(v[i], v[swapId]);
        shiftDown(swapId);
    }
    return;
}

void maxHeap::shiftUp(int i)
{
    if (i == 1)
        return;
    if (v[i] > v[parent(i)])
        swap(v[i], v[parent(i)]);
    shiftUp(parent(i));
}

void maxHeap:: display(){
    for (int i = 1; i < _size+1; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    cout << "right shift: " << (64 >> 2) << endl; // 64/2 = 32/2 = 16 // o/p: 16
    cout << "left shift: " << (4 << 3) << endl;   // 4*2 = 8*2 = 16*2 = 32 // o/p: 32
    maxHeap *priorityQueue = new maxHeap();
    if(priorityQueue->isEmpty()) cout << "Yes, Queue is empty\n";
    else cout << "We have a priority queue\n";
    priorityQueue->insertItem(4);
    priorityQueue->insertItem(3); // 4, 3, 1, 5, 6
    priorityQueue->insertItem(1);
    priorityQueue->insertItem(5);
    priorityQueue->insertItem(6);
    if(priorityQueue->isEmpty()) cout << "Yes, Queue is empty\n";
    else cout << "We have a priority queue\n";
    priorityQueue->display();
    return 0;
}
