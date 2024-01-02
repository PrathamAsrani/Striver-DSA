#include <bits/stdc++.h>
// https://www.geeksforgeeks.org/list-splice-function-in-c-stl/
using namespace std;

int main(){
    list<int> l1 = {1, 2, 3, 40, 50};
    for(auto i:l1) cout << i << " ";

    cout << "\nTransfer 50 at position 0: \n";
    list<int>::iterator itr = find(l1.begin(), l1.end(), 50);
    l1.splice(l1.begin(), l1, itr);
    for(auto i:l1) cout << i << " ";

    cout << "\nTransfer 40 at position 1: \n";
    itr = l1.begin();
    // advance the iterator by 1 position
    advance(itr, 1);
    list<int>::iterator _itr = find(l1.begin(), l1.end(), 40);
    l1.splice(itr, l1, _itr);
    for(auto i:l1) cout << i << " ";

    cout << "\nTransfer 3, 4, 5 of l2 in to l3 at beginning: \n";
    list<int> l2 = { 1, 2, 3, 4, 5 };
    list<int> l3 = { 6, 7, 8 };

    list<int> :: iterator l2_itr = l2.begin(), l3_itr = l3.begin();
    advance(l2_itr, 2);
    l3.splice(l3_itr, l2, l2_itr, l2.end());

    for(auto i:l3) cout << i << " ";
}