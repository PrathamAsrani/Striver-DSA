#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v = {1, 2, 2, 3, 3, 4, 5};

  // Remove consecutive duplicates from the vector.
  auto it = unique(v.begin(), v.end());

  // Erase the duplicates from the vector.
  v.erase(it, v.end());

  // Print the vector.
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
