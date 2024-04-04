#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_desc;

int main(){
    ordered_set os;
    os.insert(5);
    os.insert(2);
    os.insert(4);
    os.insert(6);

    // value at 3rd index in sorted array.
    cout << "The value at 3rd index ::" << *os.find_by_order(3) << endl;
 
    // index of number 6
    cout << "The index of number 6::" << os.order_of_key(6) << endl;
 
    // number 7 not in the set but it will show the
    // index number if it was there in sorted array.
    cout << "The index of number seven ::" << os.order_of_key(7) << endl;

    for(auto x: os){
        cout << x << " ";
    }
    cout << "\n";

    ordered_set_desc ospd;
    ospd.insert(5);
    ospd.insert(2);
    ospd.insert(4);
    ospd.insert(6);

    for(auto x: ospd){
        cout << x << " ";
    }
    cout << "\n";
    cout << "The index of number seven ::" << ospd.order_of_key(7) << endl;
    cout << "The index of number three ::" << ospd.order_of_key(3) << endl;
}