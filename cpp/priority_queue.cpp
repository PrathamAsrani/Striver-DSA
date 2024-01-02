#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    priority_queue<vector<int>> pq;

    pq.push({1, 2, 3});
    pq.push({2, 1, 1});

    while (!pq.empty()) {
        vector<int> arr = pq.top();
        pq.pop();

        for (auto i : arr) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
