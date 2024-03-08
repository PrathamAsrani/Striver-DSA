#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);

    for(auto i: dq){
        cout << i << " ";
    }
    cout << "\n";

    cout << accumulate(dq.begin(), dq.end(), 0) << "\n"; //sum of all elements in the queue
    
    dq.push_front(6);
    dq.push_front(7);
    dq.push_front(8);
    dq.push_front(9);
    dq.push_front(10);

    for(auto i: dq){
        cout << i << " ";
    }
    cout << "\n";

    cout << accumulate(dq.begin(), dq.end(), 0) << "\n"; //sum of all elements in the queue

    dq.pop_back();
    dq.pop_front();
    dq.pop_back();
    dq.pop_front();
    dq.pop_back();
    dq.pop_front();

    for(auto i: dq){
        cout << i << " ";
    }
    cout << "\n";

    cout << accumulate(dq.begin(), dq.end(), 0) << "\n"; //sum of all elements in the queue
}