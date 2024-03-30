#include <bits/stdc++.h>
using namespace std;

class ds{
    public:
        int k = 0, v = 0;
};

int main(){
    cout << "vector of ds\n";
    vector<ds> arr(5);
    for(auto &x: arr){
        x.k++, x.v++;
    }
    for(auto x: arr){
        cout << x.k << " " << x.v << "\n";
    }
}
